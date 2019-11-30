#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <openssl/rand.h>

#include "crypto.h"
#include "common.h"

#define LEDGER_FILE "ledger.bin"
#define PERMISSIONS (S_IRUSR | S_IWUSR)

void append_ledger(struct cipher_params *params) {
    int fd, ctext_len;
    unsigned char *ctext, *ctext_hash;
    char *line = 0;
    size_t len;

    printf("Please provide a line to append to ledger.\n> ");
    fflush(stdout);
    getline(&line, &len, stdin);
    params->msg = realloc(params->msg, params->len + len);
    memcpy(params->msg + params->len, line, len);
    params->len += len;

    // CONFIDENTIALITY: messages are encrypted prior to being written to file
    ctext_len = aes128_encrypt(params, &ctext);
    ctext_hash = md5_hash(ctext, ctext_len);

    fd = open(LEDGER_FILE, O_TRUNC | O_WRONLY | O_CREAT, PERMISSIONS);

    write(fd, params->key_hash, 16);
    write(fd, ctext_hash, 16);
    write(fd, params->iv, 16);
    write(fd, ctext, ctext_len);

    free(line);
    free(ctext_hash);
}

int main(int argc, char **argv) {
    struct stat st;
    struct cipher_params params;
    unsigned char *key;
    unsigned char *key_hash;

    if (argc < 2) {
        die("Usage: ./ledger <password>");
    }

    memset(&params, 0, sizeof(struct cipher_params));
    
    // hash the command-line argument to use as a key
    key = md5_hash(argv[1], strlen(argv[1]));
    // zero all but first two bytes of key. keyspace is still 256**2 -- big enough, right?
    memset(key+2, 0, 14);
    // we'll hash the key to keep in our file so we know if subsequent users are using the correct one
    key_hash = md5_hash(key, 2);

    // we'll probably need this for encryption or decryption later
    memcpy(params.key, key, 16);
    memcpy(params.key_hash, key_hash, 16);
    free(key);
    free(key_hash);

    if (stat(LEDGER_FILE, &st) != 0) {
        // file does not yet exist:  no need to check
        printf("No existing ledger: creating new\n");
        RAND_bytes(params.iv, 16);
    } else {
        // file does exist: must verify correct key usage
        unsigned char fd_key_hash[16], fd_ctext_hash[16], *ctext_hash, *ptext;
        int ctext_len = st.st_size - 48, ptext_len, i;
        int fd;

        fd = open(LEDGER_FILE, O_RDONLY, PERMISSIONS);
        read(fd, fd_key_hash, 16);

        // AUTHENTICATION via check for key equality
        if (memcmp(params.key_hash, fd_key_hash, 16) != 0) {
            die("Key hash from file is not equal to hash of provided key!");
        } else {
            dlog("Successfully verified key hash with file's!");
        }

        // key is correct, proceed
        read(fd, fd_ctext_hash, 16);
        read(fd, params.iv, 16);

        params.msg = malloc(ctext_len);
        params.len = ctext_len;
        read(fd, params.msg, ctext_len);

        ctext_hash = md5_hash(params.msg, params.len);
        // INTEGRITY via check for hash in file is as expected
        if (memcmp(ctext_hash, fd_ctext_hash, 16) != 0) {
            die("Ciphertext hash from file is not equal to actual hash -- tampering detected!");
        } else {
            dlog("Successfully verified ciphertext hash of file!");
        }
        free(ctext_hash);

        ptext_len = aes128_decrypt(&params, &ptext);

        printf("----- BEGIN LEDGER -----\n");
        for (i = 0; i < ptext_len; i++) {
            printf("%c", ptext[i]);
        }
        printf("----- END LEDGER -----\n");

        free(params.msg);
        params.msg = ptext;
        params.len = ptext_len;

        close(fd);
    }

    append_ledger(&params);
}