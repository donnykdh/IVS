#include <stdio.h>
#include <stdint.h>
uint8_t addOne(uint8_t value)
{
    return value + 1;
}
int main()
{
    typedef uint8_t (*FP_uint8_t_uint8_t)(uint8_t);
    FP_uint8_t_uint8_t myFunctionPointer = addOne;  // ()넣으면 실행하고 return 값
    uint8_t result = myFunctionPointer(5);
    return 0;

    printf("Result: %u\n", result);
}