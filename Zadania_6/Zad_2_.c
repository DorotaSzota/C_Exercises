#include <stdio.h>

int main() {
    int array[10];
    int *ptr;

    for (int i = 0; i < 10; i++) {
        array[i] = i;
    }

    ptr = array;

    for (int i = 0; i < 10; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}

