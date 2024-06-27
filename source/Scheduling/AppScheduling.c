/*
 * AppScheduling.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: USER
 */


#include "AppScheduling.h"
#include "Driver_Stm.h"
//#include "LED_Blink.h"
#include <stdio.h>

typedef struct{
    uint32 u32nuCnt1ms;
    uint32 u32nuCnt10ms;
    uint32 u32nuCnt100ms;
    uint32 u32nuCnt50ms;
    uint32 u32nuCnt500ms;
}TestCnt;

static void AppTask1ms(void);
static void AppTask10ms(void);
static void AppTask100ms(void);
static void AppTask50ms(void);
static void AppTask500ms(void);

TestCnt stTestCnt;

static void AppTask1ms(void){
    stTestCnt.u32nuCnt1ms++;
    printf("Hello\n");
}
static void AppTask10ms(void){
    stTestCnt.u32nuCnt10ms++;
    printf("Hello1\n");
}
static void AppTask100ms(void){
    stTestCnt.u32nuCnt100ms++;
    printf("Hello2\n");
}
static void AppTask50ms(void){
    printf("Hello3\n");
    //blinkLED();
}
static void AppTask500ms(void){
    stTestCnt.u32nuCnt500ms++;
    printf("Hello4\n");
    blinkLED();
}

void AppScheduling(void){
    printf("Hello8\n");
    if(stSchedulingInfo.u8nuScheduling1msFlag == 1u){
        printf("Hello5\n");
        stSchedulingInfo.u8nuScheduling1msFlag = 0u;
        AppTask1ms();

        if(stSchedulingInfo.u8nuScheduling10msFlag == 1u){
            stSchedulingInfo.u8nuScheduling10msFlag = 0u;
            AppTask10ms();
        }

        if(stSchedulingInfo.u8nuScheduling100msFlag == 1u){
            stSchedulingInfo.u8nuScheduling100msFlag = 0u;
            AppTask100ms();
        }
        if(stSchedulingInfo.u8nuScheduling50msFlag == 1u){
            stSchedulingInfo.u8nuScheduling50msFlag = 0u;
            AppTask50ms();
        }
        if(stSchedulingInfo.u8nuScheduling500msFlag == 1u){
            stSchedulingInfo.u8nuScheduling500msFlag = 0u;
            AppTask500ms();
        }
    }
}





