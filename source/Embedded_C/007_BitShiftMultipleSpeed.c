#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    // >> 연산 시간 측정
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        int result = 100 << 2;  // 예시로 100을 2로 오른쪽 시프트 연산
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf(">> 연산 실행 시간: %f 초\n", cpu_time_used);

    // * 연산 시간 측정
    start = clock();
    for (int i = 0; i < 1000000; i++) {
        int result = 100 * 4;  // 예시로 100을 2로 곱셈 연산
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("* 연산 실행 시간: %f 초\n", cpu_time_used);

    return 0;
}
