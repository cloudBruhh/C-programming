#include <stdio.h>

int main()
{
    char str[100];
    int i, count = 0;
    printf("Enter the line of text:");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == 'a' || str[i] == 'A')
        {
            count++;
        }
    }
    printf("The amount of 'A' and 'a' is %d", count);
    return 0;
}