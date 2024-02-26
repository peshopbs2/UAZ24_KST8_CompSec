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

int read_cypher(char* filename, char* cypher)
{
    FILE *file;
    
    file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("Error opening the file.");
        
        return EXIT_FAILURE;
    }
    
    if(fgets(cypher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        
        return EXIT_FAILURE;
    }
    
    fclose(file);
    
    return EXIT_SUCCESS;
}

int main() {
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    

    char cypher[MAXN];

    if( read_cypher(filename, cypher) == EXIT_SUCCESS)
    {
        int key;
        printf("Enter key:");
        scanf("%d", &key);
        
        char* result = caesar_decrypt(cypher, key);
        
        printf("%s", result);
        
        return EXIT_SUCCESS;
    }
    else
    {
        return EXIT_FAILURE;
    }
}
