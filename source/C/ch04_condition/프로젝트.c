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
    printf("������ %d�Դϴ�\n", answer);

    while(1){
        printf("1���� 100���̿� ���ڸ� �Է��ϼ��� >> ");
        scanf("%d", &input);
        
        
        if (input == answer){
            printf("�����Դϴ�\n");
            break;
        }else{
            if (input > answer){
                
                if(input > temp){
                    printf("������ 1�� %d�����Դϴ�. �ٽ��Է����ּ���\n", temp);
                }
                printf("DOWN\n");
                chance--;
            }else if (input < answer){
                
                if(input < temp){
                    printf("������ %d�� 1�����Դϴ�. �ٽ��Է����ּ���\n", temp);
                }
                printf("UP\n");
                chance--;
            }else{
                printf("�����Դϴ�\n");
                break;
            }
        }
        if (chance == 0){
            printf("��� ��ȸ�� ����߾��. �ƽ��Ե� �����߽��ϴ�");
            break;
        }
        temp = input;
        printf("%d\n", temp);
    }

}