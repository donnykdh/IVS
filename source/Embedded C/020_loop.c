#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
    float input, average = 0;
    for (int n = 1; n <= 5; n++) {
        scanf("%f", &input);
        average = ((n - 1)*average + input) / n;
        printf("average : %f\n", average);
    }
    system("pause");
    return 0;
}
