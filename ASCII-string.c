#include <stdio.h>
int main()
{
    char str[200];
    int i;
    printf("Enter the line of text:");
    fgets(str, sizeof(str), stdin);
    for (i = 0; str[i] != '\0'; i++)
    {
        printf("%d = %c \n", str[i], str[i]);
    }
    return 0;
}