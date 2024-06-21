// #include <stdio.h>
// #include <string.h>
// typedef struct
// {
//     char c_1;
//     char c_2;
//     char c_3;
//     char c_4;
//     int i_1;
// } Dest;
// // 1 바이트
// // 1 바이트
// // 1 바이트
// // 1 바이트
// // 4 바이트
// int main()
// {
//     char source[8] = {0x01, 0x02, 0x03, 0x04, 0x04, 0x03, 0x02, 0x01};
//     Dest destination;
//     memcpy(&destination, &source, sizeof(destination));

//     printf("c_1 = %02x\n", destination.c_1);
//     printf("c_2 = %02x\n", destination.c_2);
//     printf("c_3 = %02x\n", destination.c_3);
//     printf("c_4 = %02x\n", destination.c_4);
//     printf("i_1 = %08x\n", destination.i_1);
//     return 0;
// }

// #include <stdio.h>
// typedef struct
// {
//     char c_1;
//     int i_1;
//     int i_2;
// } Dest;
// // 1 바이트
// // 4 바이트
// // 4 바이트
// int main()
// {
//     char source[12] = {0x01, 0x04, 0x03, 0x02, 0x01, 0x05, 0x06, 0x07, 0x08,
//                        0x09, 0x10, 0x11};
//     Dest destination;
//     printf("sizeof(destination) = %u\n", sizeof(destination));
//     memcpy(&destination, &source, sizeof(destination));
//     printf("c_1 = %02x\n", destination.c_1);
//     printf("i_1 = %08x\n", destination.i_1);
//     printf("i_2 = %08x\n", destination.i_2);
//     return 0;
// }

#include <stdio.h>
typedef struct
{
    char c;
    //int i;
    double d;
    int i;
} Dest;
int main()
{

    // 1 바이트
    // 4 바이트
    // 8 바이트
    Dest destination;
    printf("sizeof(destination) = %u\n", sizeof(destination));
    return 0;
}