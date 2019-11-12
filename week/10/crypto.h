#include <stdlib.h>

struct cipher_params {
    char key[16];
    char key_hash[16];
    char iv[16];
    char *msg;
    size_t len;
};

/**
 * Dynamically allocates and returns an md5 hash of the provided plaintext with
 * size message_len. Size of return buffer will always be 128 bits (output
 * size of md5sum).
 */
unsigned char *md5_hash(const unsigned char *plaintext, size_t message_len);

/**
 * Dynamically allocates and returns the result of aes128cbc encryption on a
 * plaintext with provided key and iv. Size of ciphertext is returned since it
 * will be dependent on the size of the plaintext. Resultant ciphertext is not
 * null-terminated.
 */
int aes128_encrypt(struct cipher_params *params, unsigned char **ciphertext);

/**
 * Dynamically allocates and returns the result of aes128cbc decryption on a
 * ciphertext with provided key and iv. Size of plaintext is returned since it
 * will be dependent on the size of the ciphertext. Resultant plaintext is not
 * null-terminated.
 */
int aes128_decrypt(struct cipher_params *params, unsigned char **plaintext);
