#include <stdio.h>

union Data {
    int i;
    float f;
    char c;
};

int main() {
    union Data data;

    data.i = 42;
    printf("Stored int value: %d\n", data.i);

    data.f = 3.14;
    printf("Stored float value: %f\n", data.f);

    data.c = 'A';
    printf("Stored char value: %c\n", data.c);

    printf("Current int value: %d\n", data.i);
    printf("Current float value: %f\n", data.f);

    return 0;
}
