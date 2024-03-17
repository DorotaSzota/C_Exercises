/*
 Jeśli wymienimy wszystkie liczby naturalne poniżej 10, które są wielokrotnościami 3 lub 5, otrzymamy 3, 5, 6 i 9.
 Suma tych wielokrotności wynosi 23. Zakończ rozwiązanie tak, aby zwracało sumę wszystkich wielokrotności 3 lub 5
 poniżej podanej liczby. Dodatkowo, jeśli liczba jest ujemna, zwracane jest 0. Uwaga: Jeśli liczba jest wielokrotnością
 zarówno 3, jak i 5, policz ją tylko raz.
 */

#include <stdio.h>
int sumMult(int n) {
    if (n <= 0) {
        return 0;
    }
    int sum = 0;
    for (int i = 3; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int number;
    printf("Give me a number, plz: \n");
    scanf("%d", &number);

    int result = sumMult(number);
    printf("The sum of multiples of 3 or 5 below %d is: %d\n", number, result);
    return 0;
}