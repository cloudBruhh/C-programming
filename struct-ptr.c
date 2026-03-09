#include <stdio.h>

struct employee {
  char name[20];
  int age;
  float salary;
};

int main() {
  struct employee e, *ptr;
  ptr = &e;
  printf("Enter name: ");
  scanf("%s", ptr->name);
  printf("Enter age: ");
  scanf("%d", &ptr->age);
  printf("Enter salary: ");
  scanf("%f", &ptr->salary);
  printf("Employee Details:\n");
  printf("Name: %s\n", ptr->name);
  printf("Age: %d\n", ptr->age);
  printf("Salary: %.2f\n", ptr->salary);
  return 0;
}
