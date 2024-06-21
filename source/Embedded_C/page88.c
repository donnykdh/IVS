#include <stdio.h>
int add(int a, int b)
{
    return a + b;
}
int substract(int a, int b)
{
    return a - b;
}
int multiply(int a, int b)
{
    return a * b;
}
int divide(int a, int b)
{
    return a / b;
}

int main()
{ // �Լ� ������ ����
    int (*operation)(int, int) = NULL;
    int num1, num2;
    char operator;
    printf("�� ������ �Է��ϼ���: ");
    scanf("%d %d", &num1, &num2);
    printf("�����ڸ� �����ϼ��� (+, -, *, /): ");
    scanf(" %c", &operator);
    switch (operator)
    {
        // Operator���� operation�� ����
        case '+':
            operation = add;
            break;
        case '-':
            operation = substract;
            break;
        case '*':
            operation = multiply;
            break;
        case '/':
            operation = divide;
            break;
        default:
            printf("�߸��� �������Դϴ�.\n");
            return 1;
    }

    int result = operation(num1, num2);
    printf("���: %d\n", result);
    return 0;
}