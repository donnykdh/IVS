#include <stdio.h>

int main() {
    int x = 5;
    int y = 10;
    // if ( y++ && x < 0 == 15){
    if (x < 0 && y++  == 15){
        printf("이 코드는 실행되지 않습니다.\n");
    }
    printf("y = %d\n", y);

    return 0;
}


// int main() {
//     // for(int i = 0;0; i++) {
//     //     printf("Hello, world!\n");
//     // }
//     if(-1){
//         printf("hello\n");
//     }
//     system("pause");
//     return 0;
// }
