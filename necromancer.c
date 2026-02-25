// Basically the logic is as similar as yesterday's code, but we have to manage
// a army and you can find your strongest undead

#include <stdio.h>
#include <string.h>

#define MAX 10

// Structure definition
struct Undead {
  char name[50];
  char type[30];
  int health;
  int darkPower;
};

struct Undead army[MAX];
int count = 0;

// Summon new undead
void summonUndead() {
  if (count >= MAX) {
    printf("Your army is full!\n");
    return;
  }

  printf("\nEnter Undead Name: ");
  scanf(" %[^\n]", army[count].name);
  // Clear newline from buffer using getchar()
  getchar();

  printf("Enter Type (Zombie/Skeleton/Ghoul): ");
  scanf(" %[^\n]", army[count].type);
  getchar();

  printf("Enter Health Points: ");
  scanf("%d", &army[count].health);
  getchar();

  printf("Enter Dark Power Points: ");
  scanf("%d", &army[count].darkPower);
  getchar();

  count++;
  printf("Undead Summoned Successfully!\n");
}

// Display army
void showArmy() {
  if (count == 0) {
    printf("No undead in your army!\n");
    return;
  }

  printf("\n----- Your Undead Army ----\n");

  for (int i = 0; i < count; i++) {
    printf("\nName: %s\n", army[i].name);
    printf("Type: %s\n", army[i].type);
    printf("Health: %d\n", army[i].health);
    printf("Dark Power: %d\n", army[i].darkPower);
    printf("Total Strength: %d\n", army[i].health + army[i].darkPower);
  }
}

// Find strongest undead
void strongestUndead() {
  if (count == 0) {
    printf("No undead to evaluate!\n");
    return;
  }

  int maxIndex = 0;
  int maxStrength = army[0].health + army[0].darkPower;

  for (int i = 1; i < count; i++) {
    int strength = army[i].health + army[i].darkPower;

    if (strength > maxStrength) {
      maxStrength = strength;
      maxIndex = i;
    }
  }

  printf("\n Strongest Undead \n");
  printf("Name: %s\n", army[maxIndex].name);
  printf("Type: %s\n", army[maxIndex].type);
  printf("Total Strength: %d\n", maxStrength);
}

int main() {
  int choice;

  while (1) {
    printf("\n---------- NECROMANCER ARMY SYSTEM ----------\n");
    printf("1. Summon Undead\n");
    printf("2. Show Army\n");
    printf("3. Show Strongest Undead\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      summonUndead();
      break;
    case 2:
      showArmy();
      break;
    case 3:
      strongestUndead();
      break;
    case 4:
      printf("The dark ritual ends...\n");
      return 0;
    default:
      printf("Invalid choice!\n");
    }
  }

  return 0;
}
