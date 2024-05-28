#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int getRandomNumber(int level);
void showQuestion(int level, int num1, int num2);

int main(void){
    srand((unsigned int) time(NULL));
    int answer;
    int mul;
    int num1, num2;
    int level = 1;
    while(1){
        num1 = getRandomNumber(level);
        num2 = getRandomNumber(level);
        showQuestion(level, num1, num2);
        scanf("%d", &answer);
        mul = num1 * num2;
        if (answer == mul){
            printf("%d�ܰ� �����Դϴ�", level);    
            level++;
        }else{
            printf("%d�ܰ� �����Դϴ�. ���� �����Դϴ�", level);
            break;
        }
        if(level == 4){
            printf("��й�ȣ�� ��� ������ϴ�. �����Դϴ�");
            break;
        }
    }

}

int getRandomNumber(int level){
    
    return (rand() % 4 + 1) + (level - 1) * 4;
}

void showQuestion(int level, int num1, int num2){
    printf("\n%d���� �������� ����~\n", level);
    printf("��Ʈ : %d x %d >> ", num1, num2);
}