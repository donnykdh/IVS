#include <stdio.h>
void modifyValue(int *value)
{
    int tempvalue = 10;
    *value = tempvalue; // ���޵� value ���� ����
}
int main()
{
    int num = 5;
    printf("���� ��: %d\n", num);

    modifyValue(&num); // �Լ��� �ּҸ� ����
    printf("���� ��: %d\n", num);
    return 0;
}