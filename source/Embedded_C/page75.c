#include <stdio.h>
#include <stdlib.h>
int func1(int *var)
{
    int temp;
    temp = *var;
    *var = *var + 1;
    return temp;    // ��������
    //return *var;    // ��������
}
int main()
{
    int iPtr;
    iPtr = 1;
    printf("%d\n", iPtr);
    printf("%d\n", func1(&iPtr));
    printf("%d\n", iPtr);
    return 0;
}