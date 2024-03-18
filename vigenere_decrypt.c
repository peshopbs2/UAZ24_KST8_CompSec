#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* vigenereDecrypt(char* cipher, char* key)
{
    int length = strlen(cipher);
    int keyLength = strlen(key);
    char* plaintext = (char*) malloc(sizeof(char) * (length + 1));
    memset(plaintext, '\0', sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(isalpha(cipher[i]))
        {
            int shift = tolower(key[i % keyLength]) - 'a';
            
            if(islower(cipher[i])) //lowercase
            {
                plaintext[i] = 'a' + (cipher[i] - 'a' - shift + 26) % 26;
            }
            else //uppercase
            {
                plaintext[i] = 'A' + (cipher[i] - 'A' - shift + 26) % 26;
            }
        }
        else
        {
            plaintext[i] = cipher[i];    
        }
    }
    plaintext[length] = '\0';
    return plaintext;
}

int main()
{
    const int MAXN = 1024;
    char cipher[MAXN];
    printf("Enter cipher: ");
    scanf("%s", cipher);
    
    char key[MAXN];
    printf("Enter key: ");
    scanf("%s", key);
        
    char* result = vigenereDecrypt(cipher, key);
    
    printf("%s", result);
    
    return EXIT_SUCCESS;
}
