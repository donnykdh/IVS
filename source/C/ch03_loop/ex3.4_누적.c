#include <stdio.h>

int main(void){
    int tot = 0;    // ��������
    for(int i = 1; i < 11; i++){
        if(i != 10){
            printf("%d + ", i);
        }else{
            printf("%d ", i);
        }
        tot += i;
    }
    printf("= %d\n", tot);
}