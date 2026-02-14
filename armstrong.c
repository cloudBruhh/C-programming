#include <stdio.h>
#include <math.h>
int main()
{
    int num, temp, rem, digits = 0, res = 0;
    printf("Enter an integer: ");
    scanf("%d", &num);
    temp = num;

    // Count number of digits
    while (temp != 0)
    {
        temp /= 10;
        digits++;
    }

    temp = num;
    // Calculate Armstrong number
    while (temp != 0)
    {
        rem = temp % 10;
        res += pow(rem, digits);
        temp /= 10;
    }

    if (res == num)
        printf("%d is an Armstrong number.\n", num);
    else
        printf("%d is not an Armstrong number.\n", num);

    return 0;
}
