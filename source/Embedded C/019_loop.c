#include <stdio.h>
#include <stdlib.h>
int main() {
    // i는 1씩 증가, j는 2씩 증가
    for (int i = 0, j = 0; i < 10; i++, j += 2)
        printf("i: %d, j: %d\n", i, j);
    system("pause");
    return 0;
}
