#include <stdio.h>
#include <math.h>

// 팩토리얼 함수
// unsigned long long factorial(int n) {
//     if (n == 0 || n == 1) {
//         return 1;
//     }
//     return n * factorial(n - 1);
// }

double different(int n) {
    double probability = 1.0;
    for (int i = 0; i < n; i++) {
        probability *= (365.0 - i) / 365.0;
    }
    return probability;
}

double same(int n) {
    return 1.0 - different(n);
}

int main() {
    printf("studentNumber : 1, diffPercent : 1.000000\n");
    
    for (int n = 2; n <= 23; n++) {
        double probability = same(n);
        printf("studentNumber : %d, diffPercent : %.6f\n", n, probability);
    }
    
    return 0;
}
