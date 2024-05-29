#include <stdio.h>

struct student{
    int id;
    char name[20];  // char* name;
    double grade;
};
void stPrint(struct student st);    // 함수 선언

int main(void){
    struct student sArr[3] = {  {101, "홍길동", 4.43},
                                {102, "김길동", 3.43},
                                {103, "신길동", 4.01}};
    printf("학번\t이름\t학점\n");
    for(int idx = 0; idx < 3; idx++){
        stPrint(sArr[idx]);
    }
}

void stPrint(struct student st){
    printf("%d\t%s\t%.2lf\n", st.id, st.name, st.grade);
}
