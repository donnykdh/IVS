#include <stdio.h>

int main(void){
    //char* name = "jenny";   //name�� ������ �ּҷ� ���� char�� �ִ�
    char name[] = "jenny";
    // char name[] = {'j', 'e', 'n', 'n', 'y', '\0'};
    // for(int idx = 0; idx < 6; idx++){
    //     printf("index : %d : ���� : %c\n", idx, name[idx]);
    // }
    printf("%s\n", name);
}