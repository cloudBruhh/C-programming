#include <stdio.h>
#include <string.h>

int main() {
    char str[1000];

    printf("Enter text: ");
    fgets(str, sizeof(str), stdin);

    /* Strip trailing newline from fgets */
    int len = strlen(str);
    if (len > 0 && str[len - 1] == '\n') {
        str[--len] = '\0';
    }

    /* Reverse in-place by swapping from both ends */
    for (int i = 0; i < len / 2; i++) {
        char temp       = str[i];
        str[i]          = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }

    printf("Reversed: %s\n", str);

    return 0;
}
