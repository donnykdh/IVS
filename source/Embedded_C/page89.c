#include <stdio.h>
 // ���� �Լ�
double square(double x) {
 return x * x;
 }
 // ������ �Լ�
double cube(double x) {
 return x * x * x;
 }
 // ������ �Լ�
double fourthPower(double x) {
 return x * x * x * x;
 }
int main()
{
    double num;
    double (*functionPointers[])(double) = {square, cube, fourthPower};
    while(1){
        printf("�Ǽ��� �Է��ϼ��� (0�� �Է��ϸ� ����): ");
        scanf("%lf", &num);
        //printf("%d\n", sizeof(functionPointers));
        if(num == 0){
            break;
        }
        for (int i = 0; i < 3; i++) {
            printf("�Լ� %d ���: %.2f\n", i + 1, functionPointers[i](num));
        }
    }
    printf("���α׷��� �����մϴ�.\n");
    return 0;
    
}
