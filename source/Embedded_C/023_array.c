#include <stdio.h>
#include <stdlib.h>

int main()
{
    // 크기가 10인 int형 배열
    int numArr[10] = { 11, 22, 33, 44, 55, 66, 77, 88, 99, 110 };

    // 배열의 요소 개수만큼 반복
    for (int i = 0; i < sizeof(numArr) / sizeof(int); i++) {
        // 배열의 인덱스에 반복문의 변수 i를 지정
        printf("%d\n", numArr[i]);
    }
    system("pause");
    return 0;
}
