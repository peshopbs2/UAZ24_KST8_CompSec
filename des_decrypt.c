#include <stdio.h>
#include <string.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define DATA_SIZE 1024
int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    unsigned char encrypted[DATA_SIZE] = {0x26,	0xc8, 0xb4, 0xcf, 0xc2,	0x2b, 0x52, 0xbb};
    int encrypted_length = strlen(encrypted);
    
    unsigned char decrypted[DATA_SIZE];
    
    DES_key_schedule key_schedule;
    
    DES_set_key((DES_cblock *) key, &key_schedule);
    
    DES_ecb_encrypt((DES_cblock *) encrypted, (DES_cblock*) decrypted,
        &key_schedule, DES_DECRYPT);

    for(int i = 0; i < encrypted_length; i++)
    {
        printf("%c", decrypted[i]);
    }
    
    return 0;
}
