// call by value(��)
// call by reference(�ּ�)
#include <stdio.h>

int sum(int from, int to);  // �Լ� ����

int main(void){
    int a = 1, b = 100;
    int tot = sum(a, b);
    printf("%d���� %d���� �������� %d�Դϴ�\n", a, b, tot);
    a = 10; b = 100;
    tot = sum(a, b);
    printf("%d���� %d���� �������� %d�Դϴ�\n", a, b, tot);
}

int sum(int from, int to){  //�Լ� ����
    int result = 0;
    for (int i = from; i <= to; i++){
        result += i;
    }
    return result;
}