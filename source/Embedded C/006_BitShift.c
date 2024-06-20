#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned char num1 = 131;    //  131: 1000 0011
    char num2 = -125;            // -125: 1000 0011
    printf("%u\n", num1 >> 5);
    printf("%d\n", num2 >> 5);

    // char num1 = 113;    //  113: 0111 0001
    // char num2 = -15;    //  -15: 1111 0001
    // char num3, num4, num5, num6;
    // printf("%d\n", (char)(num1 << 2));
    // printf("%d\n", (char)(num2 << 2));
    // printf("%d\n", (char)(num1 << 4));
    // printf("%d\n", (char)(num2 << 4));

    // int num1 = -2000; //  -2000: 1111 1000 0011 0000
    // printf("%d\n", num1 / 256);
    // printf("%d\n", num1 >> 8);

    system("pause");    
    return 0;
}
