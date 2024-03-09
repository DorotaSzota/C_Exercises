/*
 Znajdź średnią ocen grupy pięciu uczniów z dwóch przedmiotów, matematyki i fizyki. Aby to zrobić, użyjemy dwuwymiarowej
 tablicy o nazwie grades. Oceny odpowiadające matematyce będą przechowywane w pierwszym wierszu (grades[0]), natomiast
 oceny odpowiadające fizyce będą przechowywane w drugim wierszu (grades[1]).
 */

#include <stdio.h>
#include <stdlib.h>

double calculateAverageMath (int grades[][2], int studentsNumber){
    double sumMath = 0;
    for (int i = 0; i<studentsNumber; i++){
        sumMath += grades[i][0];
    }
    return sumMath / studentsNumber;
}
double calculateAveragePhys (int grades[][2], int studentsNumber){
    double sumPhys = 0;
    for (int i = 0; i<studentsNumber; i++){
        sumPhys += grades[i][1];
    }
    return sumPhys / studentsNumber;
}

int main() {

    int grades [5][2] = {
            {5, 5},
            {4, 3},
            {2, 2},
            {1, 2},
            {4, 5}
    };
    int studentsNumber = 5;

    double avMath = calculateAverageMath(grades, studentsNumber);
    printf("The average grade in Mathematics is: %.2f\n", avMath);
    double avPhys = calculateAveragePhys(grades, studentsNumber);
    printf("The average grade in Physics is: %.2f\n", avPhys);
    return 0;
}