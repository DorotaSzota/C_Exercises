#include <stdio.h>
#include <stdlib.h>

int porownaj(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int wyszukiwanieBinarneRek(int arr[], int lewy, int prawy, int cel) {
    if (prawy >= lewy) {
        int srodek = lewy + (prawy - lewy) / 2;

        if (arr[srodek] == cel)
            return srodek;

        if (arr[srodek] > cel)
            return wyszukiwanieBinarneRek(arr, lewy, srodek - 1, cel);

        return wyszukiwanieBinarneRek(arr, srodek + 1, prawy, cel);
    }

    return -1;
}

int wyszukiwanieBinarne(int arr[], int n, int cel) {
    return wyszukiwanieBinarneRek(arr, 0, n - 1, cel);
}

int main() {
    int arr[] = {2, 1, 3, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    qsort(arr, n, sizeof(int), porownaj);

    int cel;
    printf("Podaj liczbe, ktora chcesz wyszukac: ");
    scanf("%d", &cel);

    int wynik = wyszukiwanieBinarne(arr, n, cel);
    if (wynik == -1)
        printf("Liczba %d nie zostala znaleziona w tablicy.\n", cel);
    else
        printf("Liczba %d zostala znaleziona pod indeksem %d.\n", cel, wynik);
    return 0;
}
