#include <stdio.h>

int* returnArray(int* ptr);

int main(void){
    int arr[3] = {10, 20, 30};
    int* afterArr = returnArray(arr);
    for(int idx = 0; idx < 3; idx++){
        printf("수정전 arr[%d] = %d\n", idx, arr[idx]);
    }
    for(int idx = 0; idx < 3; idx++){
        //printf("수정후 afterArr[%d] = %d\n", idx, afterArr[idx]);
        printf("수정후 afterArr[%d] = %d\n", idx, *(afterArr + idx));
    }
}

int* returnArray(int* ptr){
    //*(ptr + 1) = 99;  // arr 자체가 변한다. 
    static int resultArr[3];   // 기존 arr을 유지하기 위해 새로운 배열 선언
    for(int idx = 0; idx < 3; idx++){
        resultArr[idx] = ptr[idx];
    }       
    resultArr[1] = 99;
    return resultArr;
}