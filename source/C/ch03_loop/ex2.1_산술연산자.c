#include <stdio.h>


int main(void){
    int n1 = 33, n2 = 10;
    printf("계산결과\n");
    printf("%d %c %d = %d\n", n1, '/', n2, n1/n2);
    
    printf("%d %c %d = %.3lf\n", n1, '/', n2, (double)n1/n2);
    printf("%d %c %d = %d\n", n1, '%', n2, n1%n2);

    // 나머지 연산자 : 그룹을 나눌때
    if(n1%2 == 0){
        printf("n1은 짝수\n");
    }else{
        printf("n1은 홀수\n");
    } 
}