#include <stdio.h>

// 2�ܺ��� 7�ܱ��� ������ ���η� ��Ÿ����
int main(void){
    for (int i = 1; i <= 9; i++){
        
        for(int j = 2; j <= 7; j++){
            printf("%d x %d = %d\t", j, i, j*i);
        }
        printf("\n");
       
    }
}