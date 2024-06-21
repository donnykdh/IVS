#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[50];
    int id;
    int math_score;
    int english_score;
} Student;

double calculateAverage(Student student);
void printStudentInfo(Student student);

#ifdef FEATURE_SECOND_STUDENT
void printSecondStudentInfo(Student student);
#endif

#endif // STUDENT_H

