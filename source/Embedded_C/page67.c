#include <stdio.h>
#include <string.h>
int main()
{
    int rows = 4;         // �� ��
    int cols = 3;         // �� ��
    char arr[4][3]; // 2���� �迭 ����
    
    memset(arr, 3, sizeof(arr));
    
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            arr[i][j] = 3;
        }
    }
    // �ʱ�ȭ�� �迭�� ���� ���
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