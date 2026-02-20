#include <stdio.h>
#define N 100
int main() {
  int i = 0, j, temp, a, largest;
  int arr[N];
  printf("Enter the number of elements in the array: ");
  scanf("%d", &a);
  for (i = 0; i < a; i++) {
    printf("Enter elements of array %d: ", i + 2);
    scanf("%d", &arr[i]);
  }
  largest = arr[0]; // Initialize largest to the first element of the array
                    // you can also Initialize using largest = *p; where p is
                    // pointer to the first element of the array
  int *p = arr;
  for (i = 0; i < a; i++) {
    if (*(p + i) > largest) {
      largest = *(p + i); // Update largest if the current element is greater
    }
  }
  printf("the largest element in the array is: %d\n", largest);
  printf("\n");
  return 0;
}
