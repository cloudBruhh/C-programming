#include <stdio.h>
#include <string.h>
struct books {
  char title[50];
  char author[50];
  char subject[100];
  int book_id;
};
int main() {
  struct books b1, b2, b3, b4, b5;
  printf("Enter title: ");
  fgets(b1.title, sizeof(b1.title), stdin);
  b1.title[strcspn(b1.title, "\n")] = '\0';
  printf("Enter author: ");
  fgets(b1.author, sizeof(b1.author), stdin);
  b1.author[strcspn(b1.author, "\n")] = '\0';
  printf("Enter subject: ");
  fgets(b1.subject, sizeof(b1.subject), stdin);
  b1.subject[strcspn(b1.subject, "\n")] = '\0';
  printf("Enter book_id: ");
  scanf("%d", &b1.book_id);
  getchar();

  printf("Enter title: ");
  fgets(b2.title, sizeof(b2.title), stdin);
  b2.title[strcspn(b2.title, "\n")] = '\0';
  printf("Enter author: ");
  fgets(b2.author, sizeof(b2.author), stdin);
  b2.author[strcspn(b2.author, "\n")] = '\0';
  printf("Enter subject: ");
  fgets(b2.subject, sizeof(b2.subject), stdin);
  b2.subject[strcspn(b2.subject, "\n")] = '\0';
  printf("Enter book_id: ");
  scanf("%d", &b2.book_id);
  getchar();
  printf("Enter title: ");
  fgets(b3.title, sizeof(b3.title), stdin);
  b3.title[strcspn(b3.title, "\n")] = '\0';
  printf("Enter author: ");
  fgets(b3.author, sizeof(b3.author), stdin);
  b3.author[strcspn(b3.author, "\n")] = '\0';
  printf("Enter subject: ");
  fgets(b3.subject, sizeof(b3.subject), stdin);
  b3.subject[strcspn(b3.subject, "\n")] = '\0';
  printf("Enter book_id: ");
  scanf("%d", &b3.book_id);
  getchar();
  printf("Title \t Author \t Subject \t Book ID\n");
  printf("%s \t %s \t %s \t %d\n", b1.title, b1.author, b1.subject, b1.book_id);
  printf("%s \t %s \t %s \t %d\n", b2.title, b2.author, b2.subject, b2.book_id);
  printf("%s \t %s \t %s \t %d\n", b3.title, b3.author, b3.subject, b3.book_id);
  return 0;
}
