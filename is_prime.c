#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
bool isPrime(int x)
{
    if(x < 2)
    {
        return false;
    }
    
    bool prime = true; //да приемем, че х е просто
    for(int i = 2; i <= x / 2; i++)
    {
        if(x % i == 0)
        {
            prime = false; //намерихме делител и доказахме, че ..
        }
    }
    
    return prime;
}

int main()
{
    int x;
    scanf("%d", &x);
    
    if(isPrime(x))
    {
        printf("%d is prime", x);
    }
    else
    {
        printf("%d is not prime", x);
    }
    
    return EXIT_SUCCESS;
}
