#include <stdio.h>
#include <stdbool.h>

// �񱳿����� : < <= > >= == !=
// ���׿����� : (����) ? (������ ���϶��� ��) : (������ �����϶� ��) 
int main(void){
    int n1 = 10, n2 = 5;
    bool result = n1>=n2;   // true�� false
    printf("%d %s %d�� %s\n", n1, ">=", n2, result ? "��" : "����");
}