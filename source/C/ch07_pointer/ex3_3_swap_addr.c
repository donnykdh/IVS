#include <stdio.h>

// �ּҸ� �Ѱ��༭ �ּҷ� �޾Ƽ� swap
void swap_addr(int* a, int* b);    // �Լ� ����

int main(void){
    int a = 10, b = 20;
    printf("swap() ȣ�� �� a�ּ� = %p, a = %d, b�ּ� = %p, b = %d\n", &a, a, &b, b);
    swap_addr(&a, &b); // �Լ� ȣ��
    printf("swap() ȣ�� �� a�ּ� = %p, a = %d, b�ּ� = %p, b = %d\n", &a, a, &b, b);
}

// �Լ� ���� (�Լ� ����)
void swap_addr(int* a, int* b){ // a ��ü�� �ּ�, *a�� a�� ����Ű�� ��
    printf("�Լ��� a�ּ� = %p, a = %d, b�ּ� = %p, b = %d\n", a, *a, b, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("�Լ��� a�ּ� = %p, a = %d, b�ּ� = %p, b = %d\n", a, *a, b, *b);
}
