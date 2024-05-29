#include <stdio.h>

int* returnArray(int* ptr);

int main(void){
    int arr[3] = {10, 20, 30};
    int* afterArr = returnArray(arr);
    for(int idx = 0; idx < 3; idx++){
        printf("������ arr[%d] = %d\n", idx, arr[idx]);
    }
    for(int idx = 0; idx < 3; idx++){
        //printf("������ afterArr[%d] = %d\n", idx, afterArr[idx]);
        printf("������ afterArr[%d] = %d\n", idx, *(afterArr + idx));
    }
}

int* returnArray(int* ptr){
    //*(ptr + 1) = 99;  // arr ��ü�� ���Ѵ�. 
    static int resultArr[3];   // ���� arr�� �����ϱ� ���� ���ο� �迭 ����
    for(int idx = 0; idx < 3; idx++){
        resultArr[idx] = ptr[idx];
    }       
    resultArr[1] = 99;
    return resultArr;
}