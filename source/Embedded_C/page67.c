#include <stdio.h>
#include <string.h>
int main()
{
    int rows = 4;         // 행 수
    int cols = 3;         // 열 수
    char arr[4][3]; // 2차원 배열 선언
    
    memset(arr, 3, sizeof(arr));
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 3;
        }
    }
    // 초기화된 배열의 내용 출력
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}