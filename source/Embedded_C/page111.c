#include <stdio.h>
// #define FACTORIAL(n) ({ \
//     for(int i = 0; i <= (n); i++){\}


// })

int main()
{
    int num1 = 20;
    int num2 = 10;
    int set_bit_result = SET_BIT(num1, 1);
    int clear_bit_result = CLEAR_BIT(num2, 1);
    int toggle_bit_result = TOGGLE_BIT(num2, 1);

    printf("SET_BIT 결과: %d\n", set_bit_result);
    printf("CLEAR_BIT 결과: %d\n", clear_bit_result);
    printf("TOGGLE_BIT 결과: %d\n", toggle_bit_result);
    return 0;
}