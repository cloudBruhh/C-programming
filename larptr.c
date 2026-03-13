#include <stdio.h>
int larptr(int *a, int *b) {
  if (*a > *b) {
    return *a;
  } else {
    return *b;
  }
}
int main() {
  int x, y;
  printf("Enter two numbers: ");
  scanf("%d %d", &x, &y);
  int result = larptr(&x, &y);
  printf("The larger number is: %d\n", result);
  return 0;
}
