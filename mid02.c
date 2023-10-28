#include <stdio.h>

int main() {
    // ANSI escape code for setting text color to red
    printf("\033[31m");

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 8; j++) {
            printf("█");
        }
        printf("\n");
    }

    // Reset text color to default
    printf("\033[0m");

    return 0;
}
