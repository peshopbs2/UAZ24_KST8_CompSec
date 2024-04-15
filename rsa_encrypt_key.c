#include <stdio.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>

#define KEYFILE "public.pem"
#define BUFFER_SIZE 256

void print_hex(unsigned char *data, int length) {
    for (int i = 0; i < length; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

RSA *load_public_key(const char *filename) {
    FILE *fp = fopen(filename, "rb");
    if (fp == NULL) {
        fprintf(stderr, "Unable to open public key file %s\n", filename);
        return NULL;
    }

    RSA *rsa = PEM_read_RSAPublicKey(fp, NULL, NULL, NULL); //use this for header containing "RSA KEY"
    fclose(fp);
    if (rsa == NULL) {
        fprintf(stderr, "Error reading public key from %s\n", filename);
        ERR_print_errors_fp(stderr);
    }
    return rsa;
}

int encrypt_message(RSA *rsa, const unsigned char *plaintext, unsigned char *ciphertext) {
    int result = RSA_public_encrypt(strlen((const char *)plaintext) + 1,
                                    plaintext, ciphertext, rsa, RSA_PKCS1_OAEP_PADDING);
    if (result == -1) {
        ERR_print_errors_fp(stderr);
        return -1;
    }
    return result;
}

int main() {
    //test using https://www.lddgo.net/en/encrypt/rsa
    unsigned char plaintext[BUFFER_SIZE];
    scanf("%s", plaintext);
    unsigned char ciphertext[BUFFER_SIZE];
    int encrypted_length;

    RSA *rsa = load_public_key(KEYFILE);
    if (rsa == NULL) {
        return EXIT_FAILURE;
    }

    encrypted_length = encrypt_message(rsa, plaintext, ciphertext);
    if (encrypted_length == -1) {
        fprintf(stderr, "Error encrypting message\n");
        RSA_free(rsa);
        return EXIT_FAILURE;
    }

    printf("Encrypted message: ");
    print_hex(ciphertext, encrypted_length);

    RSA_free(rsa);
    return EXIT_SUCCESS;
}
