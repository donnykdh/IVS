/*
    ������, ������, ������, ���밥, ������ 5���� Ű�� �Է¹޾�
    ��»���
        ��� : 170.5
        ���� : ������ 190
        �ִ� : ������ 120
*/
#include <stdio.h>

int main(void){
    char* names[] = {"������", "������", "������", "���밥", "������"}; // ���ڿ� �迭
    int arrHeight[5];   // ģ���� Ű �Է� �迭
    int totHeight = 0;  // Ű ��������
    int idxMin, minHeight = 999;    // �ִܽ��� ���ϱ� ���� ������ (index, Ű)
    int idxMax, maxHeight = 0;      // ������� ���ϱ� ���� ������ (index, Ű)

    
    for (int i = 0; i < 5; i++){
        printf("%s�� Ű >> ", names[i]);
        scanf("%d", &arrHeight[i]);
        totHeight += arrHeight[i];
        if(minHeight > arrHeight[i]){
            minHeight = arrHeight[i];
            idxMin = i;
        }
        if(maxHeight < arrHeight[i]){
            maxHeight = arrHeight[i];
            idxMax = i;
        }

    }
    printf("%d\n", totHeight);
    printf("���Ű : %lf\n", totHeight/5.0);
    printf("�ִܽ� ģ�� %s�� Ű�� %d\n",names[idxMin], minHeight);
    printf("����� ģ�� %s�� Ű�� %d\n",names[idxMax], maxHeight);
    
}