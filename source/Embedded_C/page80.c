#include <stdio.h>
void modifyValue(int *value)
{
    int tempvalue = 10;

    //const temp = 10;
    //temp = 20;
    *value = tempvalue; // �����͸� ���� ���� ����
}
int main()
{
    const int num = 5; // �� ������ ���´�.
    printf("���� ��: %d\n", num);

    modifyValue(&num); // �Լ��� �����͸� ����
    printf("���� ��: %d\n", num);
    return 0;
}
// �ּҷ� �����ϸ� const���� ���� ����ȴ�.