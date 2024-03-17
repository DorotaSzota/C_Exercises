#include <stdio.h>
// Przygotuj program w którym zamiast wypisywania do konsoli “Hello, World”. Użytkownik będzie mógł wpisać swoje imię.
// Możesz do tegu użyć funkcji scanf, będzie trzeba tam przekazać wskaźnik do zmiennej. Natomiast narazie tym się nie przejmuj

int main() {
    char name [10];
    printf ("What's your name?");
    scanf("%s", name);
    printf ("Hello, %s\n", name);
    return 0;
}