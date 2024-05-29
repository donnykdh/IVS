#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// 중복되지 않는 로또 번호 6개 생성한 후 오름차순으로 정리
void sort(int* arr, int cnt);
int* make_lotto();
void swap(int* a, int* b);

int main(void){
    int* lotto = make_lotto();
    sort(lotto, 6);
    printf("생성된 로또번호 : ");
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
        int duplication_check = 1;          // 중복 확인을 위한 check
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