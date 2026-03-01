#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  int secret, guess, attempts = 0;
  int maxAttempts = 7;

  srand(time(0));            // Random seed
  secret = rand() % 100 + 1; // Random number between 1 and 100

  printf("=== Number Guessing Game ===\n");
  printf("I have chosen a number between 1 and 100.\n");
  printf("You have %d attempts.\n", maxAttempts);

  while (attempts < maxAttempts) {
    printf("\nEnter your guess: ");
    scanf("%d", &guess);
    attempts++;

    if (guess == secret) {
      printf("🎉 Correct! You guessed in %d attempts!\n", attempts);
      break;
    } else if (guess < secret) {
      printf("Too low!\n");
    } else {
      printf("Too high!\n");
    }
  }

  if (guess != secret) {
    printf("\n💀 You lost! The number was %d.\n", secret);
  }

  return 0;
}
