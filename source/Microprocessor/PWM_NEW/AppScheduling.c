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
    uint32 u32nuCnt1000ms;
}TestCnt;

static void AppTask1ms(void);
static void AppTask10ms(void);
static void AppTask100ms(void);
static void AppTask50ms(void);
static void AppTask500ms(void);
static void AppTask1000ms(void);

TestCnt stTestCnt;

static void AppTask1ms(void){
   // printf("Hello\n");
    stTestCnt.u32nuCnt1ms++;
}
static void AppTask10ms(void){
    stTestCnt.u32nuCnt10ms++;
}
static void AppTask100ms(void){
    stTestCnt.u32nuCnt100ms++;
}
static void AppTask50ms(void){
    stTestCnt.u32nuCnt100ms++;
}
static void AppTask500ms(void){
    stTestCnt.u32nuCnt500ms++;
    //printf("Hello\n");
}
static void AppTask1000ms(void){

    stTestCnt.u32nuCnt1000ms++;

    if(stTestCnt.u32nuCnt1000ms > 5 && stTestCnt.u32nuCnt1000ms <= 10){
        g_GtmTomPwmHl.tOn[0] = 0.3;
        g_GtmTomPwmHl.tOn[1] = 0.3;
        GtmTomPwmHl_run();
    }
    else{
        g_GtmTomPwmHl.tOn[0] = 0;
        g_GtmTomPwmHl.tOn[1] = 0;
        GtmTomPwmHl_run();
    }

}
void AppScheduling(void){
    //printf("Hello\n");
    if(stSchedulingInfo.u8nuScheduling1msFlag == 1u){

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
        if(stSchedulingInfo.u8nuScheduling1000msFlag == 1u){
            //printf("Hello\n");
            stSchedulingInfo.u8nuScheduling1000msFlag = 0u;
            AppTask1000ms();
        }
    }

}





