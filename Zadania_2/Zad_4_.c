#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[50];
    float finalGrade;
};

void sortStudents(struct Student *students, int size) {
    struct Student temp;
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (students[j].finalGrade < students[j + 1].finalGrade) {
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int numStudents = 100;
    struct Student students[numStudents];

    for (int i = 0; i < numStudents; ++i) {
        sprintf(students[i].name, "Student %d", i + 1);
        students[i].finalGrade = (float)(rand() % 51) / 2.0f + 25.0f;
    }

    sortStudents(students, numStudents);

    printf("Sorted list of students:\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("%s\t%.2f\n", students[i].name, students[i].finalGrade);
    }

    return 0;
}

