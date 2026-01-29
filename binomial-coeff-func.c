#include <stdio.h>
int fact1(int n)
{
    // Function to calculate factorial of n
    int p = 1, i;
    for (i = 1; i <= n; i++)
    {
        p = p * i;
    }
    return p;
}
int fact2(int r)
{
    // Function to calculate factorial of r
    int p1 = 1, i;
    for (i = 1; i <= r; i++)
    {
        p1 = p1 * i;
    }
    return p1;
}
int binom(int n, int r)
{
    if (r > n)
    {
        // Binomial coefficient is undefined for r > n
        return 0;
    }
    else
    {
        // Calculate binomial coefficient C(n, r) or nCr
        int bin;
        bin = fact1(n) / (fact2(r) * fact2(n - r));
        return bin;
    }
}
int main()
{
    int n, r, result;
    printf("Enter the value of n and r: ");
    scanf("%d%d", &n, &r);
    result = binom(n, r);
    printf("The binomial coefficient C(%d, %d) is: %d\n", n, r, result);
    return 0;
}