#include "student.h"
#include <stdio.h>

double calculateAverage(Student student) {
    return (student.math_score + student.english_score) / 2.0;
}

void printStudentInfo(Student student) {
    double average = calculateAverage(student);
    printf("First Student:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Math Score: %d\n", student.math_score);
    printf("English Score: %d\n", student.english_score);
    printf("Average Score: %.2f\n", average);
}

#ifdef FEATURE_SECOND_STUDENT
void printSecondStudentInfo(Student student) {
    double average = calculateAverage(student);
    printf("Second Student:\n");
    printf("Name: %s\n", student.name);
    printf("ID: %d\n", student.id);
    printf("Math Score: %d\n", student.math_score);
    printf("English Score: %d\n", student.english_score);
    printf("Average Score: %.2f\n", average);
}
#endif
