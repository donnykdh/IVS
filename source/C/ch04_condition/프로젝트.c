#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void){
    int chance = 5;
    int answer;
    int input;
    int temp;
    srand((unsigned)time(NULL));
    answer = rand() % 100 + 1;
    printf("정답은 %d입니다\n", answer);

    while(1){
        printf("1부터 100사이에 숫자를 입력하세요 >> ");
        scanf("%d", &input);
        
        
        if (input == answer){
            printf("정답입니다\n");
            break;
        }else{
            if (input > answer){
                
                if(input > temp){
                    printf("정답은 1과 %d사이입니다. 다시입력해주세요\n", temp);
                }
                printf("DOWN\n");
                chance--;
            }else if (input < answer){
                
                if(input < temp){
                    printf("정답은 %d과 1사이입니다. 다시입력해주세요\n", temp);
                }
                printf("UP\n");
                chance--;
            }else{
                printf("정답입니다\n");
                break;
            }
        }
        if (chance == 0){
            printf("모든 기회를 사용했어요. 아쉽게도 실패했습니다");
            break;
        }
        temp = input;
        printf("%d\n", temp);
    }

}