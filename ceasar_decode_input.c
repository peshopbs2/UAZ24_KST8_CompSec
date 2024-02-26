#include <stdlib.h>
#include <stdio.h>
#include <string.h>

const int MAXN = 1000;
    
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

int main() {
    char cypher[MAXN];
    scanf("%s", cypher);
    int key;
    printf("Enter key:");
    scanf("%d", &key);
        
    char* result = caesar_decrypt(cypher, key);
        
    printf("%s", result);
        
    return EXIT_SUCCESS;
}
