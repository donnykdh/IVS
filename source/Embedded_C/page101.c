#include <stdio.h>
#include <stdint.h>
#include <string.h>
typedef struct
{
    uint8_t SWK_EN : 3;
    uint8_t Reserved : 4;
    uint8_t BR_RATIO : 4;
    uint8_t Rserved : 4;
    uint8_t BR : 4;
} BitFieldData;

int main()
{
    BitFieldData data;

    uint8_t target;

    memcpy(&target, &data, sizeof(target));
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (target & (1 << i)) ? 1 : 0);
    }
    return 0;
}