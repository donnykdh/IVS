#include<stdio.h>
#include<stdlib.h>
int main(){
    unsigned char num1 = 131;
    char num2 = -125;
    printf("%u\n", num1 >> 5);
    printf("%d\n", num2 >> 5);

    return 0;
}