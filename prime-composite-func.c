#include <stdio.h>
int check(int n)
{
    int i;
    for (i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    int n, prime;
    printf("Enter a number:");
    scanf("%d", &n);
    prime = check(n);
    if (prime == 1)
    {
        printf("%d is prime", n);
    }
    else
    {
        printf("%d is composite", n);
    }
}