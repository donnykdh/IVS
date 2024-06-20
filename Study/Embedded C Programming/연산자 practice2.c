#include<stdio.h>
#include<stdint.h>
int main(){
    uint8_t flags = 0;

    

    for(int i = 0; i < 8; i++){
        printf("Fail_%d: %d\n", i, flags);
    }
    printf("\n");
    system("pause");
    return 0;
}