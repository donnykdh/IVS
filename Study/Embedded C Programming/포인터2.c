// #include <stdio.h>
// int main()
// {
//     int array[5] = {10, 20, 30, 40, 50}; // 5���� ������ ������ �迭 ����
//     int *ptr1 = &array[0];               // 0 ��° ������ ���� ������ �Ҵ�
//     int *ptr2 = &array[4];               // 4 ��° ������ ���� ������ �Ҵ�
//     int difference = ptr2 - ptr1;        // �� �������� ����

//     printf("0 ��° ������ ��: %p\n", *ptr1);
//     printf("4 ��° ������ ��: %p\n", *ptr2);
//     printf("0 ��° ������ 4 ��° ������ ����: %d\n", difference);
//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     // �迭�� �����ϰ� �� �Ҵ�
//     int numArr[10] = {11, 22, 33, 44, 55, 66, 77, 88, 99, 110};
//     printf("%d\n", 0[numArr]);
//     printf("%d\n", 2[numArr]);
//     printf("%d\n", 4[numArr]);
//     system("pause");
//     return 0;
// }

#include <stdio.h>
#include <stdlib.h>
int main()
{

    int numArr[3][4] = {
        {11, 22, 33, 44},
        {55, 66, 77, 88},
        {99, 110, 121, 132}};
    // printf("%d\n", numArr[0][0]);
    // printf("%d\n", numArr[1][2]);
    // printf("%d\n", numArr[2][0]);
    // printf("%d\n", numArr[2][3]);
    printf("%d\n", 0 [(0 [numArr])]);
    printf("%d\n", 2 [(1 [numArr])]);
    printf("%d\n", 0 [(2 [numArr])]);
    printf("%d\n", 3 [(2 [numArr])]);

    return 0;
}