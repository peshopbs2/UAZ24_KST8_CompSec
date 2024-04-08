#include <stdio.h>
#include <string.h>
#include <openssl/des.h>
#define KEY_SIZE 8
#define DATA_SIZE 8
int main()
{
    unsigned char key[KEY_SIZE] = "banichka";
    
    unsigned char input[DATA_SIZE] = "12345678";
    
    unsigned char output[DATA_SIZE];
    
    DES_key_schedule key_schedule;
    
    DES_set_key((DES_cblock *) key, &key_schedule);
    
    DES_ecb_encrypt((DES_cblock *) input, (DES_cblock*) output,
        &key_schedule, DES_ENCRYPT);

    for(int i = 0; i < DATA_SIZE; i++)
    {
        printf("%02x", output[i]);
    }
    
    return 0;
}
