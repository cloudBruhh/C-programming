#include <stdio.h>
#include <string.h>

#define MAX 100

struct Account {
  char name[50];
  int account_number;
  double balance;
};

struct Account accounts[MAX];
int count = 0;

void createAccount() {
  if (count >= MAX) {
    printf("Maximum account limit reached.\n");
    printf("Well there is a unnecessary surplus of accounts:");
    printf("You can not create more accounts.\n");
    return;
  }
  // Create a new account
  printf("Enter name: ");
  scanf("%s", accounts[count].name);
  getchar(); // Consume newline character left by previous input
  printf("Enter account number: ");
  scanf("%d", &accounts[count].account_number);
  getchar(); // Consume newline character left by previous input
  printf("Enter initial balance: ");
  scanf("%lf", &accounts[count].balance);
  getchar(); // Consume newline character left by previous input
  count++;
  printf("Account created successfully.\n");
}

// Function to search for an account by account number
int AccountSearch(int accNo) {
  for (int i = 0; i < count; i++) {
    if (accounts[i].account_number == accNo) {
      return i;
    }
  }
  return -1; // Account not found
}

// Checl deposit function

void deposit() {
  int accNo;
  double amount; // Declare amount as double to match the balance type
  printf("Enter account number: ");
  scanf("%d", &accNo);
  getchar(); // Consume newline character left by previous input
  int index = AccountSearch(accNo);
  if (index == -1) {
    printf("Account not found.\n");
    return;
  }
  printf("Enter amount to deposit: ");
  scanf("%lf", &amount);
  getchar(); // Consume newline character left by previous input
  accounts[index].balance += amount;
  printf("Deposit successful. New balance: %.2lf\n", accounts[index].balance);
}

void withdraw() {
  int accNo;
  double amount; // Declare amount as double to match the balance type
  printf("Enter account number: ");
  scanf("%d", &accNo);
  getchar(); // Consume newline character left by previous input
  int index = AccountSearch(accNo);
  if (index == -1) {
    printf("Account not found.\n");
    return;
  }
  printf("Enter amount to withdraw: ");
  scanf("%lf", &amount);
  getchar(); // Consume newline character left by previous input
  if (accounts[index].balance < amount) {
    printf("Insufficient balance.\n");
    return;
  }
  accounts[index].balance -= amount;
  printf("Withdrawal successful. New balance: %.2lf\n",
         accounts[index].balance);
}

void displayAccount() {
  int accNo;
  printf("Enter account number: ");
  scanf("%d", &accNo);
  getchar(); // Consume newline character left by previous input
  int index = AccountSearch(accNo);
  if (index == -1) {
    printf("Account not found.\n");
    return;
  }
  printf("\n Your account details are:\n");
  printf("Name: %s\n", accounts[index].name);
  printf("Account Number: %d\n", accounts[index].account_number);
  printf("Balance: %.2lf\n", accounts[index].balance);
}

int main() {
  int choice;

  while (1) {
    printf("\n Welcome the the Bank Management System:");
    printf("\n------Bank Management System ------\n");
    printf("1. Create Account \n");
    printf("2. Deposit \n");
    printf("3. Withdraw \n");
    printf("4. See your account\n");
    printf("5. Exit \n");
    printf("Enter the number of the action you want to perform:");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      createAccount();
      break;
    case 2:
      deposit();
      break;
    case 3:
      withdraw();
      break;
    case 4:
      displayAccount();
      break;
    case 5:
      printf(
          "Thank you for choosing to bank with the Banking Management System");
      return 0;
    default:
      printf("Well you have to choose one of the above option, dont you?");
    }
  }
  return 0;
}
