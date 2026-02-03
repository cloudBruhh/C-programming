#include <stdio.h>
int main()
{
    int i;
    printf("Enter the value of ASCII character:");
    scanf("%d", &i);
    if (i <= 32)
    {
        printf("ASCII values from 0 to 32 are non-printable characters.\n");
    }
    else
    {
        for (i = 33; i < 128; i++)
        {
            printf("ASCII value of %c = %d\n", i, i);
        }
    }
    return 0;
}