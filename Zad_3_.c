/*
 Oblicz silnie gdzie parametrem wejściowym jest tablica int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }; .
 Ma być to funkcja która przyjmuje tablice a następnie liczy silnie dla każdej liczby w tej tablicy.
 */

#include <stdio.h>
int calulateFactiorial (int array[]){
    for (int i = 0; i < 10; i++){
        int result = 1;
        for (int j = 1; j <= array[i]; j++){
            result *= j;
        }
        printf("Factorial %d is %d\n", array[i], result);
    }
}

int main() {
    int array[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    calulateFactiorial(array);

    return 0;
}
