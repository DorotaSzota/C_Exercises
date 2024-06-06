#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct {
    int red;
    int green;
    int blue;
} Dice;

int main() {
    FILE *file = fopen("input2.txt", "r"); // Here should be a path to the file, in my case it was the iCloud address, but I changed it to the local one 'cause I don't want to share the path on my GH account ;-)
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char line[256];
    int total_sum = 0;
    int power_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "Game") != NULL) {
            int game_id;
            sscanf(line, "Game %d:", &game_id);

            int possible = 1;
            Dice min_dice = {INT_MAX, INT_MAX, INT_MAX};
            char *token = strtok(line, ";");
            while (token != NULL) {
                int r = 0, g = 0, b = 0;
                sscanf(token, "%d red, %d green, %d blue", &r, &g, &b);
                if (r > 12 || g > 13 || b > 14) {
                    possible = 0;
                }
                if (r < min_dice.red) min_dice.red = r;
                if (g < min_dice.green) min_dice.green = g;
                if (b < min_dice.blue) min_dice.blue = b;
                token = strtok(NULL, ";");
            }

            if (possible) {
                total_sum += game_id;
            }

            int power = min_dice.red * min_dice.green * min_dice.blue;
            power_sum += power;
        }
    }

    fclose(file);

    printf("Sum of possible game IDs: %d\n", total_sum);
    printf("Sum of powers of minimum sets: %d\n", power_sum);
    // The answer is: Sum of possible game IDs: 3849
    // The answer is: Sum of powers of minimum sets: 0

    return 0;
}

