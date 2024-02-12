#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int x;
    scanf("%d", &x);
    
    bool* arr = (bool*) malloc( (x+1) * sizeof(bool));
    
    memset(arr, false, (x+1) * sizeof(bool));
    
    for(int i = 2; i <= x; i++)
    {
        for(int j = i * 2; j <= x; j += i)
        {
            arr[j] = true;
        }
    }
    
    for(int i = 2; i <= x; i++)
    {
        if(!arr[i]) // arr[i] == false
        {
            printf("%d ", i);
        }
    }

    free(arr);

    return EXIT_SUCCESS;
}
