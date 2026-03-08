#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Player {
  int hp;
  int attack;
  int gold;
  int level;
  int potions;
};

struct Enemy {
  int hp;
  int attack;
};

void generateEnemy(struct Enemy *e, int level) {
  e->hp = (rand() % 20 + 20) + level * 5;
  e->attack = (rand() % 5 + 5) + level;
}

void attackEnemy(struct Player *p, struct Enemy *e) {
  int crit = rand() % 5 == 0; // 20% crit chance
  int damage = p->attack + (crit ? p->attack : 0);

  printf("\nYou attack for %d damage%s!\n", damage,
         crit ? " (CRITICAL HIT)" : "");
  e->hp -= damage;
}

void enemyAttack(struct Player *p, struct Enemy *e) {
  printf("Enemy attacks for %d damage!\n", e->attack);
  p->hp -= e->attack;
}

int main() {
  srand(time(0));

  struct Player player = {100, 10, 0, 1, 3};
  int choice;

  printf("=== WELCOME TO DUNGEON RAID ===\n");

  while (player.hp > 0) {
    struct Enemy enemy;
    generateEnemy(&enemy, player.level);

    printf("\nA Level %d enemy appears! (HP: %d)\n", player.level, enemy.hp);

    while (enemy.hp > 0 && player.hp > 0) {
      printf("\nYour HP: %d | Potions: %d\n", player.hp, player.potions);
      printf("1. Attack\n2. Use Potion\n3. Run\nChoose: ");
      scanf("%d", &choice);

      if (choice == 1) {
        attackEnemy(&player, &enemy);
        if (enemy.hp > 0)
          enemyAttack(&player, &enemy);
      } else if (choice == 2) {
        if (player.potions > 0) {
          player.hp += 20;
          player.potions--;
          printf("You healed 20 HP!\n");
        } else {
          printf("No potions left!\n");
        }
      } else if (choice == 3) {
        printf("You escaped!\n");
        break;
      } else {
        printf("Invalid choice!\n");
      }
    }

    if (player.hp <= 0)
      break;

    if (enemy.hp <= 0) {
      printf("\nEnemy defeated!\n");
      player.gold += 20;
      player.level++;
      player.attack += 2;
      player.potions++;

      printf("You leveled up! Level %d\n", player.level);
    }
  }

  printf("\n=== GAME OVER ===\n");
  printf("Final Level: %d | Gold: %d\n", player.level, player.gold);

  return 0;
}
