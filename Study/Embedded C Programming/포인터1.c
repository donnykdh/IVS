// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     // �����ͺ�������
//     int *numPtr;
//     int num1 = 10;
//     // num1�Ǹ޸��ּҸ�
//     // �����ͺ���������
//     numPtr = &num1;
//     printf("%p, %d\n", numPtr, *numPtr);
//     printf("%p, %d\n", &num1, num1);
//     printf("%d\n", sizeof(numPtr));
//     printf("%d\n", sizeof(int *));
//     printf("%d\n", sizeof(char *));

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>
int main()
{
    long long *numPtr1; // long long�������ͼ���
    float *numPtr2;
    char *cPtr1;

    // float�� �����ͼ���
    // char�������ͼ���
    long long num1 = 10;
    float num2 = 3.5f;
    char c1 = 'a';
    numPtr1 = &num1;
    numPtr2 = &num2;
    cPtr1 = &c1;
    printf("%lld\n", *numPtr1);
    printf("%f\n", *numPtr2);
    printf("%c\n", *cPtr1);

    return 0;
}