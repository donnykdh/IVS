#include <stdio.h>
#include <time.h>

int main() {
    const int iterations = 10000000;
    clock_t start, end;
    double cpu_time_used;

    // Float 연산 시간 측정
    start = clock();
    for (int i = 0; i < iterations; i++) {
        float a = 3.14;
        float b = 2.0;
        float result = a * b;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Float 연산 시간: %f 초\n", cpu_time_used);

    //int
    start = clock();
    for (int i = 0; i < iterations; i++) {
        int a = 314;
        int b = 20;
        int result = a * b;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("int 연산 시간: %f 초\n", cpu_time_used);

    //long long int
    start = clock();
    for (int i = 0; i < iterations; i++) {
        long long int a = 314;
        long long int b = 20;
        long long int result = a * b;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("long long int 연산 시간: %f 초\n", cpu_time_used);

    // Double 연산 시간 측정
    start = clock();
    for (int i = 0; i < iterations; i++) {
        double a = 3.14;
        double b = 2.0;
        double result = a * b;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Double 연산 시간: %f 초\n", cpu_time_used);

    return 0;
}
