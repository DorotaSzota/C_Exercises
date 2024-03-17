#include <stdio.h>

int main() {
    int variable = 10;
    int *pointer = &variable;

    printf("Before:\n");
    printf("Value of the variable directly: %d\n", variable);
    printf("Value of the variable through pointer: %d\n", *pointer);

    *pointer = 20;

    printf("After:\n");
    printf("Value of the variable directly: %d\n", variable);
    printf("Value of the variable through pointer: %d\n", *pointer);

    return 0;
}

