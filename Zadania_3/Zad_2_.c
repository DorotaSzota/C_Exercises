#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int **alokujPamiecMacierzy(int wiersze, int kolumny) {
    int **macierz = (int **)malloc(wiersze * sizeof(int *));

    for (int i = 0; i < wiersze; i++) {
        macierz[i] = (int *)malloc(kolumny * sizeof(int));
    }
    return macierz;
}

void wypelnijMacierzLosowymi(int **macierz, int wiersze, int kolumny) {
    srand(time(NULL));

    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            macierz[i][j] = rand() % 100;
        }
    }
}

void wyswietlMacierz(int **macierz, int wiersze, int kolumny) {
    printf("Wygenerowana macierz:\n");
    for (int i = 0; i < wiersze; i++) {
        for (int j = 0; j < kolumny; j++) {
            printf("%4d ", macierz[i][j]);
        }
        printf("\n");
    }
}

void zwolnijPamiecMacierzy(int **macierz, int wiersze) {
    for (int i = 0; i < wiersze; i++) {
        free(macierz[i]);
    }
    free(macierz);
    printf("Zwolniono pamiec.\n");
}

int main() {
    int wiersze, kolumny;

    printf("Podaj liczbe wierszy macierzy: ");
    scanf("%d", &wiersze);
    printf("Podaj liczbe kolumn macierzy: ");
    scanf("%d", &kolumny);

    int **macierz = alokujPamiecMacierzy(wiersze, kolumny);

    wypelnijMacierzLosowymi(macierz, wiersze, kolumny);

    wyswietlMacierz(macierz, wiersze, kolumny);

    zwolnijPamiecMacierzy(macierz, wiersze);

    return 0;
}

