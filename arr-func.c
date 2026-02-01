#include <stdio.h>
#define N 100
void function(int a[], int n);
int main()
{
    int a[N], i;
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("Enter elements of array %d: ", i + 1);
        scanf("%d", &a[i]);
    }
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\nAfter: ");
    function(a, n);
    printf("The elements of the array are: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}
void function(int x[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        x[i] = x[i] * 2;
    }
}