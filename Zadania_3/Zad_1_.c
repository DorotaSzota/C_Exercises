#include <stdio.h>

int wartoscTrojkataPascala(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return wartoscTrojkataPascala(n - 1, k - 1) + wartoscTrojkataPascala(n - 1, k);
    }
}

void wyswietlTrojkatPascala(int wysokosc) {
    for (int i = 0; i < wysokosc; i++) {
        for (int j = 0; j <= i; j++) {
            printf("%d ", wartoscTrojkataPascala(i, j));
        }
        printf("\n");
    }
}

int main() {
    int wysokosc;

    printf("Podaj wysokosc trojkata Pascala: ");
    scanf("%d", &wysokosc);

    wyswietlTrojkatPascala(wysokosc);

    return 0;
}
