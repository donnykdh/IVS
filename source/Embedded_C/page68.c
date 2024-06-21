#include <stdio.h>
#include <string.h>
int main()
{
    int source[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; // 원본
    int destination[10];                              // 대상
    // memcpy를 사용하여 데이터 복사
    memcpy(destination, source, sizeof(source));
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", destination[i]);
    }
    printf("\n");

    return 0;
}

// 초기화 할 때 많이 쓰인다. 주소를 그대로 복사해서 가져와서 하나씩 
// 넣는 것보다 빠르다.
// 