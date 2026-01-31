#include <stdio.h>

int fact(int n);
int binom(int n, int r);

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * fact(n - 1);
}

int binom(int n, int r)
{
    if (r > n)
    {
        return 0;
    }
    else
    {
        int bin;
        bin = fact(n) / (fact(r) * fact(n - r));
        return bin;
    }
}

int main()
{
    int r, n, result;
    printf("Enter the value of n and r: ");
    scanf("%d%d", &n, &r);
    result = binom(n, r);
    printf("The binomial coefficient C(%d, %d) is: %d\n", n, r, result);
    return 0;
}