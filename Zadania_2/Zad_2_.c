#include <stdio.h>

void modifyValue(float *ptr) {
    *ptr *= 2;
}

int main() {
    float variable = 3.5;
    float *pointer = &variable;

    printf("Initial value of the variable: %.2f\n", variable);

    modifyValue(pointer);

    printf("The new value of the variable after modification: %.2f\n", variable);

    return 0;
}
