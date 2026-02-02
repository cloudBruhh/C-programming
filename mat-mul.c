#include <stdio.h>
#define N 100

void input(int a[N][N], int r, int c);
void process(int a[N][N], int b[N][N], int c[N][N], int r1, int c1, int c2);
void output(int c[N][N], int r, int col);

int main()
{
    int a[N][N], b[N][N], C[N][N];
    int r1, c1, r2, c2;

    printf("Enter rows and columns for first matrix: ");
    scanf("%d%d", &r1, &c1);

    printf("Enter rows and columns for second matrix: ");
    scanf("%d%d", &r2, &c2);

    if (c1 != r2)
    {
        printf("Error: Matrices cannot be multiplied.\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    input(a, r1, c1);

    printf("Enter elements of second matrix:\n");
    input(b, r2, c2);

    process(a, b, C, r1, c1, c2);
    output(C, r1, c2);
    return 0;
}

void input(int a[N][N], int r, int col)
{
    int i, j;
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
}

void process(int a[N][N], int b[N][N], int c[N][N], int r1, int c1, int c2)
{
    int i, j, k;
    for (i = 0; i < r1; i++)
    {
        for (j = 0; j < c2; j++)
        {
            c[i][j] = 0;
            for (k = 0; k < c1; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

void output(int c[N][N], int r, int col)
{
    int i, j;
    printf("Resultant Matrix:\n");
    for (i = 0; i < r; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", c[i][j]);
        }
        printf("\n");
    }
}