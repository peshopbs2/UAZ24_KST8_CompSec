#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024

char* caesar_decrypt(char* cypher, int key)
{
    int length = strlen(cypher);
    char* str = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(cypher[i] != '\0')
    {
        str[i] = ((cypher[i] - 'A' - key + 26) % 26) + 'A';
        i++;
    }
    str[i] = '\0';
    
    return str;
}

int main()
{
    
    char cypher[MAXN];
    scanf("%s", cypher);
    
    for(int i = 0; i < 26; i++)
    {
        char* decoded = caesar_decrypt(cypher, i);
        printf("Key: %d, Decoded: %s\n", i, decoded);
    }
    return EXIT_SUCCESS;
}
