#include <stdio.h>

int main(void){
    int input;
    printf("��� �������� ����ұ� >> ");
    scanf("%d", &input);
    printf("%d�� �������Դϴ�\n", input);
    
    for(int i = 1; i <=9 ; i++){
        printf("%d x %d = %d\n", input, i, input*i);
    }

}