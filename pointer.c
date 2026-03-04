#include <stdio.h>
int main()
{
  int a, b, sum;
  int *ptr1, *ptr2, *ptr_sum;
  printf("Enter two numbers: ");
  scanf("%d %d", &a, &b);
  ptr1 = &a;       
  ptr2 = &b;
  ptr_sum = &sum;
  *ptr_sum = *ptr1 + *ptr2; // dereference ptr1 and ptr2 to get values and add them
  printf("Sum: %d\n", sum);
  return 0;
}
