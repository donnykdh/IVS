// #include<stdio.h>
// #include<stdint.h>
// #include<stdlib.h>
// /*
// Current Data:
// Current 1: 164
// Current 2: 32
// Current 3: 0
// Current 4: 4

// Gsensor Data:
// Gsensor 1: 32
// Gsensor 2: 38
// Gsensor 3: 4
// Gsensor 4: A
// 결과가 이렇게 나와야돼
// */
// int main()
// {
//     uint8_t canDataArray[8] = {0x64, 0xC9, 0x00, 0x00, 0x01, 0x32, 0x4E, 0x28};

//     currentData1 = (canDataArray[0]) | (((uint16_t)canDataArray[1] & 0x03) << 8);


//     printf("Current Data: \n");
//     printf("Current 1: %x\n", currentData1);
//     printf("Current 2: %x\n", currentData2);
//     printf("Current 3: %x\n", currentData3);
//     printf("Current 4: %x\n", currentData4);
    
//     printf("\nGsensor Data: \n");
//     printf("Gsensor 1: %x\n", gsensor1);
//     printf("Gsensor 2: %x\n", gsensor2);
//     printf("Gsensor 3: %x\n", gsensor3);
//     printf("Gsensor 4: %x\n", gsensor4);
//     system("pause");
//     return 0;
// }


