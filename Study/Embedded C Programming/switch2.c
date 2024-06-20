#include<stdio.h>
#include<stdlib.h>

int main(){
    unsigned int c;
    system("chcp 65001");
    scanf("%d", &c);
    switch(c){
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        printf("5보다 작거나 같은 수\n");
        break;

    }
    return 0;
}