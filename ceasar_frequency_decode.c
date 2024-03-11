#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 1024
#define LETTER_COUNT 26

char* read_cypher(char* filename)
{
    FILE *file;
    
    file = fopen(filename, "r");
    
    if(file == NULL)
    {
        printf("Error opening the file.");
        
        return NULL;
    }
    
    char* cypher = (char*) malloc(sizeof(char) * MAXN);
    
    if(fgets(cypher, MAXN, file) == NULL)
    {
        printf("Error reading from file.");
        
        return NULL;
    }
    
    fclose(file);
    
    return cypher;
}

void print_frequencies(int* arr)
{
    for(int i = 0; i < LETTER_COUNT; i++)
    {
        printf("%c -> %d times\n", ('a' + i), arr[i]);
    }
}

int* count_frequencies(char * cypher)
{
    int* frequency = (int*) malloc(sizeof(int) * LETTER_COUNT);
    
    memset(frequency, 0, sizeof(int) * LETTER_COUNT);
    
    int index = 0;
    while(cypher[index] != '\0')
    {
        char letter = cypher[index] - 'A';
        //TODO: change for different letters
        frequency[letter]++;
        index++;
    }
    
    return frequency;
}

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

char* frequency_decode(char* cypher)
{
    int* frequencies = count_frequencies(cypher);
    int maxIndex = 0;
    for(int i = 0; i < LETTER_COUNT; i++)
    {
        if(frequencies[i] > frequencies[maxIndex])
        {
            maxIndex = i;
        }
    }
    
    int key = maxIndex - ('E' - 'A');
    
    return caesar_decrypt(cypher, key);
}

int main()
{
    char filename[MAXN];
    printf("Enter filename: \n");
    scanf("%s", filename);
    

    char* cypher = read_cypher(filename);
    printf("Cypher: %s\n", cypher);
    char* decoded = frequency_decode(cypher);
    
    printf("Decoded: %s", decoded);
    return EXIT_SUCCESS;
}
