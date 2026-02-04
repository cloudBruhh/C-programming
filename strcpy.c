#include <stdio.h>
#include <string.h>
int main()
{
    char a[100] = "Hello, World!";
    char b[100] = "World,Hello! ";
    printf("Before copying:%s%s \n", a, b);
    strcpy(a, b);
    printf("After copying:%s%s \n", a, b);
    return 0;
}