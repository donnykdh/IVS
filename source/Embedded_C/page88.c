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
{ // 함수 포인터 선언
    int (*operation)(int, int) = NULL;
    int num1, num2;
    char operator;
    printf("두 정수를 입력하세요: ");
    scanf("%d %d", &num1, &num2);
    printf("연산자를 선택하세요 (+, -, *, /): ");
    scanf(" %c", &operator);
    switch (operator)
    {
        // Operator별로 operation을 대입
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
            printf("잘못된 연산자입니다.\n");
            return 1;
    }

    int result = operation(num1, num2);
    printf("결과: %d\n", result);
    return 0;
}