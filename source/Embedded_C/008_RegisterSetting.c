
#include <stdio.h>

#define SWK_EN_BIT   7
#define BR_BIT       0

int main() {

    unsigned char registerValue = 0;

    registerValue |= (1 << SWK_EN_BIT);

    registerValue |= (4 << BR_BIT);

    printf("Register Value: %x\n", registerValue);
    for (int i = 7; i >= 0; i--) {
        printf("%d", (registerValue & (1 << i)) ? 1 : 0);
    }
    printf("\n");
    return 0;
}