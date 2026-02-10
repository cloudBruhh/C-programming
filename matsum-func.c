#include <stdio.h>
#define N 10
void input(int a[N][N], int n);
void process(int a[N][N], int b[N][N], int c[N][N], int n);
void output(int c[N][N], int n);

int main()
{
    int n;
    printf("Enter the number of rows/cols (max 10): ");
    scanf("%d", &n);

    int a[N][N], b[N][N], c[N][N];
    input(a, n);
    input(b, n);
    process(a, b, c, n);
    output(c, n);
    return 0;
}

void input(int a[N][N], int n)
{
    int i, j;
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void process(int a[N][N], int b[N][N], int c[N][N], int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void output(int c[N][N], int n)
{
    int i, j;
    printf("Resultant Matrix after addition:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}