#include <stdio.h>

void sum(int form, int to, int* tot);

int main(void){
    int a = 1, b = 10;
    int* tot; // tot가 가리키는 곳  
    sum(a, b, &tot);
    printf("%d부터 %d까지 누적합은 %d입니다\n", a, b, tot);
    a = 10; b = 100;
    sum(a, b, &tot);
    printf("%d부터 %d까지 누적합은 %d입니다\n", a, b, tot);
}

void sum(int from, int to, int* tot){
    *tot = 0; //tot가 가리키는 곳의 값
    for(int i = from; i <= to; i++){
        *tot += i;
    }
}