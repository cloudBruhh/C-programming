#include <stdio.h>
#define N 5
int main()
{
  int a[N], *p,i,sum=0,*ps;
  p = a;
  printf("Enter %d integers:\n",N);
  for(i=0;i<N;i++){
    scanf("%d",p);
    p++;
  }
  p -= N;
  *ps = sum;

  for(i=0;i<N;i++){
    *ps += *p;
    p++;
  }
  printf("The sum is %d\n",*ps);
  return 0;
}
