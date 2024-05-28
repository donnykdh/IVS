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
            printf("%d단계 정답입니다", level);    
            level++;
        }else{
            printf("%d단계 오답입니다. 실패 종료입니다", level);
            break;
        }
        if(level == 4){
            printf("비밀번호를 모두 맞췄습니다. 성공입니다");
            break;
        }
    }

}

int getRandomNumber(int level){
    
    return (rand() % 4 + 1) + (level - 1) * 4;
}

void showQuestion(int level, int num1, int num2){
    printf("\n%d레벨 구구단을 외자~\n", level);
    printf("힌트 : %d x %d >> ", num1, num2);
}