#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// �ߺ����� �ʴ� �ζ� ��ȣ 6�� ������ �� ������������ ����
void sort(int* arr, int cnt);
int* make_lotto();
void swap(int* a, int* b);

int main(void){
    int* lotto = make_lotto();
    sort(lotto, 6);
    printf("������ �ζǹ�ȣ : ");
    for(int i = 0; i < 6; i++){
        printf("%d\t", lotto[i]);
    }
}

int* make_lotto(){
    static int lotto[6];
    srand((unsigned int) time(NULL));
    int i = 0;
    while(i < 6){
        int temp = rand() % 45 + 1;
        int duplication_check = 1;          // �ߺ� Ȯ���� ���� check
        for(int idx = 0; idx < i; idx++){
            if (temp == lotto[idx]){
                duplication_check = 0;
                break;
            }
        }
        if(duplication_check){
            lotto[i] = temp;
            i++;
        }
    }
    return lotto;
}

void sort(int* arr, int cnt){
    for(int i = 0; i < cnt - 1; i++){
        for(int j = i + 1; j < cnt; j++){
            if(arr[i] >= arr[j]){
                swap(&arr[i], &arr[j]);
            }
        }
    }
}

void swap(int* a, int* b){ 
    int temp = *a;
    *a = *b;
    *b = temp;
}