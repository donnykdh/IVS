#include <stdio.h>

void sum(int form, int to, int* tot);

int main(void){
    int a = 1, b = 10;
    int* tot; // tot�� ����Ű�� ��  
    sum(a, b, &tot);
    printf("%d���� %d���� �������� %d�Դϴ�\n", a, b, tot);
    a = 10; b = 100;
    sum(a, b, &tot);
    printf("%d���� %d���� �������� %d�Դϴ�\n", a, b, tot);
}

void sum(int from, int to, int* tot){
    *tot = 0; //tot�� ����Ű�� ���� ��
    for(int i = from; i <= to; i++){
        *tot += i;
    }
}