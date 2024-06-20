#include <stdio.h>
#include <stdint.h>

int main() {
    uint8_t flags = 0;

    flags |= 1u << 0; // Fail_0
    flags |= 0u << 1; // Fail_1
    flags |= 1u << 2; // Fail_2
    flags |= 1u << 3; // Fail_3
    flags |= 0u << 4; // Fail_4
    flags |= 1u << 5; // Fail_5
    flags |= 0u << 6; // Fail_6
    flags |= 1u << 7; // Fail_7
    
    // Fail_0부터 Fail_7까지 값을 검색하고 출력합니다.

    for (int i = 0; i < 8; i++) {
        int flag = (flags >> i) & 1u;
        printf("Fail_%d: %d\n", i, flag);
    }

    return 0;
}