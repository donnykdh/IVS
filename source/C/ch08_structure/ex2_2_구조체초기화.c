#include <stdio.h>

struct student{ // 구조체 정의
    int num;        // student 구조체 멤버
    double grade;   // student 구조체 멤버
};

int main(void){
    int i = 1;
    struct student s1 = {101, 4.43};
    s1.num = 101;
    s1.grade = 2.56;
    printf("학번 = %d, 학점 = %.2lf\n", s1.num, s1.grade);
}