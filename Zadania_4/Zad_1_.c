#include <stdio.h>

unsigned int factorial(int n) {

    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int n;
    printf("Podaj liczbe calkowita: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Blad! Liczba musi byc nieujemna.\n");
        return 1;
    }

    printf("%d! = %llu\n", n, factorial(n));

    return 0;
}
