#include <stdio.h>
#include <string.h>
#include <ctype.h>
// I know this exercise from the advent of code 2023, Lukasz ;-)
#define MAX_LINE_LENGTH 100
#define NUM_WORDS 9

// Define the words and their corresponding digits
const char *words[NUM_WORDS] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
const int word_values[NUM_WORDS] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

// A function to find the numeric value of a word if it matches any known word
int word_to_digit(const char *str) {
    for (int i = 0; i < NUM_WORDS; i++) {
        if (strcmp(str, words[i]) == 0) {
            return word_values[i];
        }
    }
    return -1;
}

int main() {
    FILE *file = fopen("input.txt", "r"); // Here should be a path to the file, in my case it was the iCloud address, but I changed it to the local one 'cause I don't want to share the path on my GH account ;-)
    if (file == NULL) {
        printf("Could not open file.\n");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    int total_sum = 0;

    while (fgets(line, sizeof(line), file)) {
        int first_digit = -1, last_digit = -1;
        char *token = strtok(line, " \n");

        while (token != NULL) {
            // Check if token is a digit
            if (isdigit(token[0])) {
                if (first_digit == -1) {
                    first_digit = token[0] - '0';
                }
                last_digit = token[strlen(token) - 1] - '0';
            } else {
                // Check if token matches any known word representing a digit
                int digit = word_to_digit(token);
                if (digit != -1) {
                    if (first_digit == -1) {
                        first_digit = digit;
                    }
                    last_digit = digit;
                }
            }
            token = strtok(NULL, " \n");
        }

        if (first_digit != -1 && last_digit != -1) {
            total_sum += first_digit * 10 + last_digit;
        }
    }

    fclose(file);

    printf("Sum of all energy values: %d\n", total_sum);
    // The answer is: Sum of all energy values: 35097

    return 0;
}
