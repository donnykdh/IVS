#include <stdio.h>

// ��Ʈ������ : &(and), |(or), ^(XOR:������ 0, �ٸ��� 1)
int main(void){
    int n1 = 10;    // 0 ~ 0 1 0 1 0
    int n2 = 6;     // 0 ~ 0 0 1 1 0
    // n1 & n2 :       0 ~ 0 0 0 1 0
    // n1 | n2 :       0 ~ 0 1 1 1 0
    // n1 ^ n2 :       0 ~ 0 1 1 0 0
    printf("n1&n2 = %d\n", n1&n2);
    printf("n1|n2 = %d\n", n1|n2);
    printf("n1^n2 = %d\n", n1^n2);
    printf("n2 << 1 = %d\n", n2<<1);    // 0 ~ 0 0 1 1 0 0 (1 shift�� 2��)
}