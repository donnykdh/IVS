#include <stdio.h>
#include <string.h>
int main()
{
    int arr[10];
    // �迭�� 3���� �ʱ�ȭ
    memset(arr, 3, sizeof(arr));

    // �ʱ�ȭ�� �迭�� ���� ���
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}