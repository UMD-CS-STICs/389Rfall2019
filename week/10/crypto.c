#include <openssl/evp.h>
#include <string.h>

#include "crypto.h"
#include "common.h"

unsigned char *md5_hash(const unsigned char *plaintext, size_t message_len) {
    unsigned char *result;
    EVP_MD_CTX *mdctx;

    if ((mdctx = EVP_MD_CTX_create()) == 0) {
        die("Failed to create hash context");
    } else if (1 != EVP_DigestInit_ex(mdctx, EVP_md5(), 0)) {
        die("Failed to initialize sha128 context");
    } else if (1 != EVP_DigestUpdate(mdctx, plaintext, message_len)) {
        die("Failed to update hash context with message");
    } else if ((result = (unsigned char*) malloc(EVP_MD_size(EVP_md5()))) == 0) {
        die("Failed to allocate hash return buffer");
    } else if (1 != EVP_DigestFinal_ex(mdctx, result, 0)) {
        die("Failed to finalize hash");
    }

    EVP_MD_CTX_destroy(mdctx);

    return result;
}

int aes128_encrypt(struct cipher_params *params, unsigned char **ciphertext) {
    EVP_CIPHER_CTX *ctx;
    unsigned char output[(params->len)+16];
    int len;
    int ciphertext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        die("Failed to create encryption context");
    } else if (1 != EVP_EncryptInit_ex(ctx, EVP_aes_128_cbc(), 0, params->key, params->iv)) {
        die("Failed to initialize encryption context");
    } else if (1 != EVP_EncryptUpdate(ctx, output, &len, params->msg, params->len)) {
        die("Failed to update encryption context");
    }

    ciphertext_len = len;

    if (1 != EVP_EncryptFinal_ex(ctx, output+len, &len)) {
        die("Failed to finalize encrypt");
    }

    ciphertext_len += len;

    if (!(*ciphertext = malloc(ciphertext_len))) {
        die("Failed to allocate ciphertext");
    }
    memset(*ciphertext, 0, ciphertext_len);
    memcpy(*ciphertext, output, ciphertext_len);

    EVP_CIPHER_CTX_free(ctx);

    return ciphertext_len;
}

int aes128_decrypt(struct cipher_params *params, unsigned char **plaintext) {
    EVP_CIPHER_CTX *ctx;
    unsigned char output[params->len];
    int len;
    int plaintext_len;

    if (!(ctx = EVP_CIPHER_CTX_new())) {
        die("Failed to create decryption context");
    } else if (1 != EVP_DecryptInit_ex(ctx, EVP_aes_128_cbc(), 0, params->key, params->iv)) {
        die("Failed to initalize decryption context");
    } else if (1 != EVP_DecryptUpdate(ctx, output, &len, params->msg, params->len)) {
        die("Failed to update decryption context");
    }

    plaintext_len = len;

    if (1 != EVP_DecryptFinal_ex(ctx, output+len, &len)) {
        die("Failed to finalize decryption");
    }

    plaintext_len += len;

    if (!(*plaintext = malloc(plaintext_len))) {
        die("Failed to allocate plaintext");
    }
    memset(*plaintext, 0, plaintext_len);
    memcpy(*plaintext, output, plaintext_len);

    EVP_CIPHER_CTX_free(ctx);

    return plaintext_len;
}
