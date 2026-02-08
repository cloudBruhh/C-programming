#include <stdio.h>

int main()
{
    char a[200], b[200];
    int i, k, j;
    printf("Enter the first string:");
    fgets(a, sizeof(a), stdin);
    printf("Enter the second string:");
    fgets(b, sizeof(b), stdin);

    printf("\n 1. For copying string 1 to string 2 \n 2. For concatenating string 1 and string 2 \n 3.Length of both strings \n 4. For comparing string 1 and string 2 \n");
    printf("Enter your choice:");
    scanf("%d", &k);
    switch (k)
    {
    case 1:
        i = 0;
        while (b[i] != '\0')
        {
            a[i] = b[i];
            i++;
        }
        a[i] = '\0';
        printf("String 1 after copying string 2: %s\n", a);
        break;
    case 2:

        i = 0;
        for (i = 0; a[i] != '\0'; i++)
            ;
        for (j = 0; b[j] != '\0'; j++)
        {
            a[i] = b[j];
            i++;
        }
        a[i] = '\0';
        printf("String 1 after concatenation: %s\n", a);
        fflush(stdout);
        break;
    case 3:
        i = 0;
        while (a[i] != '\0')
        {
            i++;
        }
        j = 0;
        while (b[j] != '\0')
        {
            j++;
        }
        printf("Length of string 1: %d\n", i);
        printf("Length of string 2: %d\n", j);
        break;
    case 4:
        i = 0;
        int equal = 1;
        while (a[i] != '\0' && b[i] != '\0')
        {
            if (a[i] != b[i])
            {
                printf("Strings are not equal.\n");
                equal = 0;
                break;
            }
            i++;
        }
        if (equal && a[i] == '\0' && b[i] == '\0')
        {
            printf("Strings are equal.\n");
        }
        else if (equal)
        {
            printf("Strings are not equal.\n");
        }
        break;
    }
}