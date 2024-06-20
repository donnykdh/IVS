#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
    int num1;
    scanf("%d", &num1);    // 값을 입력받음
    switch (num1)   // num1의 값에 따라 분기
    {
    case 1:         // 1일 때
        printf("1입니다.\n");
        break;
    case 2:         // 2일 때
        printf("2입니다.\n");
        break;
    default:  // 해당 Case 가 없을 때
        printf("default\n");
        break;
    }
    system("pause");
    return 0;
}
