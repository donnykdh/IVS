#include <stdio.h>

struct student{
    int id;
    char name[20];  // char* name;
    double grade;
};
void stPrint(struct student st);    // �Լ� ����

int main(void){
    struct student sArr[3] = {  {101, "ȫ�浿", 4.43},
                                {102, "��浿", 3.43},
                                {103, "�ű浿", 4.01}};
    printf("�й�\t�̸�\t����\n");
    for(int idx = 0; idx < 3; idx++){
        stPrint(sArr[idx]);
    }
}

void stPrint(struct student st){
    printf("%d\t%s\t%.2lf\n", st.id, st.name, st.grade);
}
