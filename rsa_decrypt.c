#include <stdio.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/err.h>
#define MAXN 4096
void printErrors()
{
    ERR_print_errors_fp(stderr);
    abort();
}

RSA *loadPrivateKey(const char *filename)
{
    FILE *keyFile = fopen(filename, "rb");
    if(!keyFile) {
        fprintf(stderr, "Unable to open file");
        return NULL;
    }
    
    RSA *rsa_private = PEM_read_RSAPrivateKey(keyFile, NULL, NULL, NULL);
    fclose(keyFile);
    
    if(!rsa_private)
    {
        fprintf(stderr, "Failed to load private key");
        return NULL;
    }
    
    return rsa_private;
}

int hexStringToBinary(const char *hex, unsigned char *binary)
{
    int len = 0;
    for(int i = 0; hex[i] != '\0' && hex[i+1] != '\0'; i+=2){
        sscanf(&hex[i], "%2hhx", &binary[len]);
        len++;
    }
    return len;
}

int decryptRSA(RSA *rsa, const unsigned char *encrypt,
        int encryptLen, unsigned char *decrypt)
{
    return RSA_private_decrypt(encryptLen, encrypt, decrypt, rsa,
        RSA_PKCS1_OAEP_PADDING);
}

int main()
{
    const char *privateKeyFilename = "private.pem";
    RSA *rsa_private = loadPrivateKey(privateKeyFilename);
    if(!rsa_private)
    {
        return EXIT_FAILURE;
    }
    
    char hex[MAXN];
    scanf("%s", hex);
    unsigned char encrypt[MAXN];
    int encryptLen = hexStringToBinary(hex, encrypt);
    
    unsigned char decrypt[MAXN];
    int decryptLen = decryptRSA(rsa_private, encrypt, encryptLen, decrypt);
    if(decryptLen == -1)
    {
        printErrors();
    }
    
    printf("Decrypted: %.*s\n", decryptLen, decrypt);
    RSA_free(rsa_private);
    
    return EXIT_SUCCESS;
}
