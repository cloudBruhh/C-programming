// calculate time using structure
#include <stdio.h>
#define N 100
struct time {
  int hour;
  int minute;
  int second;
};

int main() {
  struct time t1, t2, t3;

  printf("Enter the time in hour minute and second:");
  scanf("%d %d %d", &t1.hour, &t1.minute, &t1.second);
  printf("Enter the time in hour minute and second:");
  scanf("%d %d %d", &t2.hour, &t2.minute, &t2.second);

  t3.hour = t1.hour + t2.hour;
  t3.minute = t1.minute + t2.minute;
  t3.second = t1.second + t2.second;

  while (t3.second >= 60) {
    t3.second -= 60;
    t3.minute++;
  }
  while (t3.minute >= 60) {
    t3.minute -= 60;
    t3.hour++;
  }

  printf("The total time is %d:%d:%d", t3.hour, t3.minute, t3.second);
}
