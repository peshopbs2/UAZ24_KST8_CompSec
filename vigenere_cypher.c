#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

char* vigenereEncrypt(char* plaintext, char* key)
{
    int length = strlen(plaintext);
    int keyLength = strlen(key);
    char* cipher = (char*) malloc(sizeof(char) * (length + 1));
    memset(cipher, '\0', sizeof(char) * (length + 1));
    for(int i = 0; i < length; i++)
    {
        if(isalpha(plaintext[i]))
        {
            //if we have a letter
            int shift = tolower(key[i % keyLength]) - 'a';
            
            if(islower(plaintext[i])) //lowercase
            {
                cipher[i] = 'a' + (plaintext[i] - 'a' + shift) % 26;
            }
            else //uppercase
            {
                cipher[i] = 'A' + (plaintext[i] - 'A' + shift) % 26;
            }
        }
        else
        {
            cipher[i] = plaintext[i];    
        }
    }
    cipher[length] = '\0';
    return cipher;
}

int main()
{
    const int MAXN = 1024;
    char text[MAXN];
    printf("Enter text: ");
    scanf("%s", text);
    
    char key[MAXN];
    printf("Enter key: ");
    scanf("%s", key);
    
    char* cipher = vigenereEncrypt(text, key);
    
    printf("%s", cipher);
    
    return EXIT_SUCCESS;
}
