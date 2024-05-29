#include <stdio.h>

// 주소를 넘겨줘서 주소로 받아서 swap
void swap_addr(int* a, int* b);    // 함수 선언

int main(void){
    int a = 10, b = 20;
    printf("swap() 호출 전 a주소 = %p, a = %d, b주소 = %p, b = %d\n", &a, a, &b, b);
    swap_addr(&a, &b); // 함수 호출
    printf("swap() 호출 후 a주소 = %p, a = %d, b주소 = %p, b = %d\n", &a, a, &b, b);
}

// 함수 구현 (함수 정의)
void swap_addr(int* a, int* b){ // a 자체가 주소, *a는 a가 가르키는 값
    printf("함수안 a주소 = %p, a = %d, b주소 = %p, b = %d\n", a, *a, b, *b);
    int temp = *a;
    *a = *b;
    *b = temp;
    printf("함수안 a주소 = %p, a = %d, b주소 = %p, b = %d\n", a, *a, b, *b);
}
