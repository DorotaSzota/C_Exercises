#include <stdio.h>

int add(int a, int b) {
    return a + b;
}

int multiply(int a, int b) {
    return a * b;
}

int subtract(int a, int b) {
    return a - b;
}

int main() {
    int (*func_ptr)(int, int);
    int choice, x, y;

    printf("Choose operation:\n");
    printf("1. Add\n");
    printf("2. Multiply\n");
    printf("3. Subtract\n");
    scanf("%d", &choice);

    printf("Enter two integers: ");
    scanf("%d %d", &x, &y);

    switch (choice) {
        case 1:
            func_ptr = add;
            break;
        case 2:
            func_ptr = multiply;
            break;
        case 3:
            func_ptr = subtract;
            break;
        default:
            printf("Invalid choice\n");
            return 1;
    }

    int result = func_ptr(x, y);
    printf("Result: %d\n", result);

    return 0;
}
