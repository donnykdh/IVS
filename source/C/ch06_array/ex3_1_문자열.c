#include <stdio.h>

int main(void){
    //char* name = "jenny";   //name의 변수에 주소로 가면 char이 있다
    char name[] = "jenny";
    // char name[] = {'j', 'e', 'n', 'n', 'y', '\0'};
    // for(int idx = 0; idx < 6; idx++){
    //     printf("index : %d : 글자 : %c\n", idx, name[idx]);
    // }
    printf("%s\n", name);
}