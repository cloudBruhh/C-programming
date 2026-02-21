#include <stdio.h>
struct student {
  char name[20];
  int age;
  float score;
};
int main() {
  struct student s;
  printf("Enter name: ");
  scanf("%s", s.name);
  printf("Enter age: ");
  scanf("%d", &s.age);
  printf("Enter score: ");
  scanf("%f", &s.score);

  printf("Name: %s\n", s.name);
  printf("Age: %d\n", s.age);
  printf("Score: %.2f\n", s.score);
  return 0;
}
