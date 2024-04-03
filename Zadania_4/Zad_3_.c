#include <stdio.h>

void zamien(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutuj(int *array, int start, int end) {
    if (start == end) {
        for (int i = 0; i <= end; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    } else {
        for (int i = start; i <= end; i++) {
            zamien(&array[start], &array[i]);
            permutuj(array, start + 1, end);
            zamien(&array[start], &array[i]);
        }
    }
}

int main() {
    int array[] = {1, 2, 3};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Permutacje ciagu:\n");
    permutuj(array, 0, n - 1);

    return 0;
}
