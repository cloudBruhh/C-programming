#include <stdio.h>
#define N 100
int main() {
  int a[N], *p;
  int i;
  for (i = 0; i < N; i++) {
    printf("Enter the number of elements: ", i + 1);
    scanf("%d", &a[i]);
  }
  p = a;
  for (i = 1; i < N; i++) {
    if (*p < *(p + i)) {
      *p = *(p + i);
    }
    printf("The largest number is: %d\n", *p);
    return 0;
  }
