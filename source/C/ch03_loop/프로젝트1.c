#include <stdio.h>

// 2단부터 7단까지 구구단 가로로 나타내기
int main(void){
    for (int i = 1; i <= 9; i++){
        
        for(int j = 2; j <= 7; j++){
            printf("%d x %d = %d\t", j, i, j*i);
        }
        printf("\n");
       
    }
}