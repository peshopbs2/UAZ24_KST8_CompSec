#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char* caesar_cypher(char* str, int key)
{
    int length = strlen(str);
    char* cypher = (char*) malloc(sizeof(char) * (length + 1));
    
    int i = 0;
    while(str[i] != '\0')
    {
        //TODO: check for lower, upper, digits and special
        cypher[i] = ((str[i] - 'A' + key) % 26) + 'A';
        i++;
    }
    cypher[i] = '\0';
    
    return cypher;
}

int main() {
    const int MAXN = 1000;
    char str[MAXN];
    scanf("%s", str);
    
    int length = strlen(str);
    int key;
    printf("Enter key:");
    scanf("%d", &key);
    
    char* cypher = caesar_cypher(str, key);
    
    printf("%s", cypher);
    
    return EXIT_SUCCESS;
}
