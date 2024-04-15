#include <stdio.h>
#include <stdlib.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <openssl/err.h>

void clear(BIO *bp_public, BIO *bp_private, RSA *r, BIGNUM* big)
{
    BIO_free_all(bp_public);
    BIO_free_all(bp_private);
    RSA_free(r);
    BN_free(big);
}

int main()
{
    int ret = 0;
    RSA* r = NULL;
    BIGNUM* big = NULL;
    BIO* bp_public = NULL, *bp_private = NULL;
    int bits = 2048;
    unsigned long e = RSA_F4;
    
    //1. Generate RSA key
    big = BN_new();
    if(big == NULL)
    {
        fprintf(stderr, "Error allocating BIGNUM\n");
        return EXIT_FAILURE;
    }
    
    ret = BN_set_word(big, e);
    if(ret != 1)
    {
        fprintf(stderr, "Error setting exponent\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    
    //2. Save the RSA key
    r = RSA_new();
    if(r == NULL)
    {
        fprintf(stderr, "Error allocating RSA\n");
        return EXIT_FAILURE;
    }
    ret = RSA_generate_key_ex(r, bits, big, NULL);
    if(ret != 1)
    {
        fprintf(stderr, "Error generating RSA key.\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    bp_public = BIO_new_file("public.pem", "w+");
    if(bp_public == NULL)
    {
        fprintf(stderr, "Error opening public key file.\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    ret = PEM_write_bio_RSAPublicKey(bp_public, r);
    if(ret != 1)
    {
        fprintf(stderr, "Error writing public key file.\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    //3. Save the private key
    bp_private = BIO_new_file("private.pem", "w+");
    if(bp_private == NULL)
    {
        fprintf(stderr, "Error opening private key file.\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }

    ret = PEM_write_bio_RSAPrivateKey(bp_private, r, NULL, NULL, 0, NULL, NULL);
    if(ret != 1)
    {
        fprintf(stderr, "Error writing private key to file.\n");
        clear(bp_public, bp_private, r, big);
        return EXIT_FAILURE;
    }
    
    
    printf("RSA public and private keys have been generated\n");
    
    return EXIT_SUCCESS;
}
