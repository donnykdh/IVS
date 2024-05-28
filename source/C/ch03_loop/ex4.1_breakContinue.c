#include <stdio.h>

int main(void){
    for(int i = 1; i <= 5; i++){
        if(i == 3){
            // break;
            continue;
        }
        printf("%d\t", i);
    }
}