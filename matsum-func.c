#include <stdio.h>
#define N 10
void input(int a[N][N]);
void process(int a[N][N], int b[N][N], int c[N][N]);
void output(int c[N][N]);
int main()
{
    int a[N][N], b[N][N], c[N][N];
    input(a);
    input(b);
    process(a, b, c);
    output(c);
    return 0;
}
void input(int a[N][N])
{
    int i, j;
    printf("Enter elements of the matrix:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}
void process(int a[N][N], int b[N][N], int c[N][N])
{
    int i, j;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}
void output(int c[N][N])
{
    int i, j;
    printf("Resultant Matrix after addition:\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}