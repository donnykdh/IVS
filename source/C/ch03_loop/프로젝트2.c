#include <stdio.h>

int main(void){
    int floor = 4 ;
    // printf("¸î´Ü ÇÇ¶ó¹Ìµå¸¦ ½×À»±î¿ä(5~20)?");
    // scanf("%d", &floor);
    for(int i=0 ; i<floor ; i++){
        for(int j=i ; j<floor ; j++){
            printf(" "); //ºóÄ­ Ãâ·Â
        }
        for(int k=0 ; k<i*2+1 ; k++){
            printf("*");
        }
        printf("\n");
    }
}