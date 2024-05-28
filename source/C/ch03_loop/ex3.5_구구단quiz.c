#include <stdio.h>

int main(void){
    int input;
    printf("몇단 구구단을 출력할까 >> ");
    scanf("%d", &input);
    printf("%d단 구구단입니다\n", input);
    
    for(int i = 1; i <=9 ; i++){
        printf("%d x %d = %d\n", input, i, input*i);
    }

}