#include <stdio.h>

struct student{ // ����ü ����
    int num;        // student ����ü ���
    double grade;   // student ����ü ���
};

int main(void){
    int i = 1;
    struct student s1 = {101, 4.43};
    s1.num = 101;
    s1.grade = 2.56;
    printf("�й� = %d, ���� = %.2lf\n", s1.num, s1.grade);
}