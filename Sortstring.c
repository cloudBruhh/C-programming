#include <stdio.h>
#include <string.h>
#define N 100
  void inputNames(char names[N][N],int n)
  {
  int i;
      for (i=0;i < n; i++)
      {
        printf("Enter Names:");
        scanf("%s",names[i]);
      }
  }
  void sortNames(char names[N][N], int n)
  {
  int i,j;
  char temp[N];
  for(i=0; i < n; i++){
  for(j=i+1;j < n-1; j++){
    if (strcmp(names[i],names[j]) > 0){
    strcmp(temp, names[i]);
    strcmp(names[i],names[j]);
    strcmp(names[j], temp);
      }
    }
  }
  }
void displayNames(char names[N][N], int n)
{
  int i;
  printf("\n Names in Ascending order is:");
  for(i=0;i<n;i++){
    printf("%s \n", names[i]);
  }
}
int main()
{
  int n;
  char names[N][N];

  printf("Enter number of names:");
  scanf("%d", &n);
  inputNames(names,n);
  sortNames(names,n);
  displayNames(names,n);
  return 0;
}

