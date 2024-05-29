#include <stdio.h>

// �迭���� ���� �������� �����ϴ� �Լ��� �����Ͻÿ�
void sort(int* arr, int cnt);
void swap(int* a, int* b);

int main(void){
    int lotto[6] = {41, 1, 35, 20, 45, 10};
    printf("������ : ");
    for(int idx = 0; idx < 6; idx++){
        printf("%d\t", lotto[idx]);
    }
    sort(lotto, 6);
    printf("\n������ : ");
    for(int idx = 0; idx < 6; idx++){
        printf("%d\t", lotto[idx]);
    }
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