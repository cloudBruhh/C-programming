#include <stdio.h>
struct time {
  int hours;
  int minutes;
  int seconds;
};
int main() {
  struct time t1;
  printf("Enter hours: ");
  scanf("%d", &t1.hours);
  printf("Enter minutes: ");
  scanf("%d", &t1.minutes);
  printf("Enter seconds: ");
  scanf("%d", &t1.seconds);
  if (t1.hours < 0 || t1.hours > 23) {
    printf("Invalid hours. Please enter a value between 0 and 23.\n");
    return 1;
  }
  if (t1.minutes < 0 || t1.minutes > 59) {
    printf("Invalid minutes. Please enter a value between 0 and 59.\n");
    return 1;
  }
  if (t1.seconds < 0 || t1.seconds > 59) {
    printf("Invalid seconds. Please enter a value between 0 and 59.\n");
    return 1;
  }
  printf("Time: %d:%d:%d\n", t1.hours, t1.minutes, t1.seconds);
  return 0;
}
