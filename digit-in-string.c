#include <stdio.h>
int main()
{
    char str[200];
    int i, count = 0;
    printf("Enter the line of text:");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            count++;
        }
    }
    printf("The number of digits in the string is: %d\n", count);
    return 0;
}