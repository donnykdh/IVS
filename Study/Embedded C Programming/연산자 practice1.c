#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned char registerValue = 0;

    

    for(int i = 7; i >= 0; i--){
        printf("%d", (registerValue & (1 << i)) ? 1 : 0);
    }
    printf("\n");
    system("pause");
    return 0;
}