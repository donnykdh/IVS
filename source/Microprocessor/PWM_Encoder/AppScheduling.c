/*
 * AppScheduling.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: USER
 */


#include "AppScheduling.h"
#include "Driver_Stm.h"
#include "IfxPort.h"
#include "UART.h"
#include "IfxPort_PinMap.h"
#include <stdio.h>


typedef struct {
    uint32 pulseCount;
    uint8 lastA;
    uint8 lastB;
} EncoderState;

EncoderState encoderState = {0, 0, 0};

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

//static void AppNoTask(void);

uint8 ENCA;
uint8 ENCB;

TestCnt stTestCnt;
float theta = 0, theta_old = 0, w = 0, w_old = 0, w_RPM = 0;
float t = 0, Ts = 0.001;


static void AppTask1ms(void) {
    stTestCnt.u32nuCnt1ms++;
    updateEncoder();  // 엔코더 업데이트 함수 호출

    theta = (float)encoderState.pulseCount;  // 엔코더 펄스를 각도로 변환 (단순화)
    w = (theta - theta_old) / Ts;
    w_RPM = (w * 60) / (2 * 3.141592);
    theta_old = theta;
    w_old = w;


    _out_uart3_INT(encoderState.pulseCount);
    _out_uart3('\n');
    _out_uart3('\r');

}

//static void AppTask1ms(void){
//    stTestCnt.u32nuCnt1ms++;
//}
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

void initEncoder(void) {

    IfxPort_setPinModeInput(IfxPort_P02_1.port, IfxPort_P02_1.pinIndex, IfxPort_InputMode_pullDown);
    IfxPort_setPinModeInput(IfxPort_P02_0.port, IfxPort_P02_0.pinIndex, IfxPort_InputMode_pullDown);


    encoderState.lastA = IfxPort_getPinState(&MODULE_P02, 1);
    encoderState.lastB = IfxPort_getPinState(&MODULE_P02, 0);
}

void updateEncoder(void) {
    // 현재 상태
    uint8 currentA = IfxPort_getPinState(&MODULE_P02, 1);
    uint8 currentB = IfxPort_getPinState(&MODULE_P02, 0);

    if (encoderState.lastA != currentA || encoderState.lastB != currentB) { // 상태 변화 일어나면
        if (encoderState.lastA == 0 && currentA == 1) { // A 상승 에지
            if (currentB == 0) {
                encoderState.pulseCount++;
            } else {
                encoderState.pulseCount--;
            }
        } else if (encoderState.lastA == 1 && currentA == 0) {
            // A 하강 에지
            if (currentB == 1) {
                encoderState.pulseCount++;
            } else {
                encoderState.pulseCount--;
            }
        }
        // 상태 업데이트
        encoderState.lastA = currentA;
        encoderState.lastB = currentB;
    }
}

//static void AppNoTask(void){
//    IfxPort_setPinModeInput(IfxPort_P02_1.port, IfxPort_P02_1.pinIndex, IfxPort_InputMode_pullDown);
//    IfxPort_setPinModeInput(IfxPort_P02_0.port, IfxPort_P02_0.pinIndex, IfxPort_InputMode_pullDown);
//    ENCA = IfxPort_getPinState(&MODULE_P02, 1);
//    ENCB = IfxPort_getPinState(&MODULE_P02, 0);
//    if(ENCA == FALSE && ENCB == FALSE){
//        S = 0;
//    }
//    else if(ENCA == FALSE && ENCB == TRUE){
//        S = 1;
//    }
//    else if(ENCA == TRUE && ENCB == TRUE){
//        S = 2;
//    }
//    else if(ENCA == TRUE && ENCB == FALSE){
//        S = 3;
//    }
//}

void controlMotor(float dutyCycle) {
    // PWM 설정 (예: IfxGtm_Tom_PwmHl)
    // dutyCycle은 0.0에서 1.0 사이의 값이어야 합니다.
//    IfxGtm_Tom_PwmHl_setOnTime(&g_GtmTomPwmHl.drivers.pwm, (uint32)(dutyCycle * IfxGtm_Tom_Timer_getPeriod(&g_GtmTomPwmHl.drivers.timer)));
//    IfxGtm_Tom_Timer_applyUpdate(&g_GtmTomPwmHl.drivers.timer);
    Ifx_TimerValue onTime[2];
    onTime[0] = (Ifx_TimerValue)(dutyCycle * IfxGtm_Tom_Timer_getPeriod(&g_GtmTomPwmHl.drivers.timer));
    onTime[1] = (Ifx_TimerValue)(dutyCycle * IfxGtm_Tom_Timer_getPeriod(&g_GtmTomPwmHl.drivers.timer));

    IfxGtm_Tom_PwmHl_setOnTime(&g_GtmTomPwmHl.drivers.pwm, onTime);
    IfxGtm_Tom_Timer_applyUpdate(&g_GtmTomPwmHl.drivers.timer);
}

void AppScheduling(void){

    //AppNoTask();
    updateEncoder();

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
            stSchedulingInfo.u8nuScheduling1000msFlag = 0u;
            AppTask1000ms();
        }
    }

}








//#include "AppScheduling.h"
//#include "Driver_Stm.h"
//#include "IfxPort.h"
//#include "IfxGtm_Tom_PwmHl.h"
//#include <stdio.h>
//
//// 엔코더 A, B 채널 핀 정의
//#define ENCODER_A_PIN IfxPort_P02_1
//#define ENCODER_B_PIN IfxPort_P02_0
//
//typedef struct {
//    uint32_t pulseCount;
//    uint8_t lastA;
//    uint8_t lastB;
//} EncoderState;
//
//EncoderState encoderState = {0, 0, 0};
//
//void initEncoder(void) {
//    // 엔코더 A, B 핀을 입력 모드로 설정
//    IfxPort_setPinModeInput(ENCODER_A_PIN.port, ENCODER_A_PIN.pinIndex, IfxPort_InputMode_pullDown);
//    IfxPort_setPinModeInput(ENCODER_B_PIN.port, ENCODER_B_PIN.pinIndex, IfxPort_InputMode_pullDown);
//
//    // 초기 상태 읽기
//    encoderState.lastA = IfxPort_getPinState(&MODULE_P02, 1);
//    encoderState.lastB = IfxPort_getPinState(&MODULE_P02, 0);
//}
//
//void updateEncoder(void) {
//    // 현재 상태 읽기
//    uint8_t currentA = IfxPort_getPinState(&MODULE_P02, 1);
//    uint8_t currentB = IfxPort_getPinState(&MODULE_P02, 0);
//
//    // 상태 변화 확인
//    if (encoderState.lastA != currentA || encoderState.lastB != currentB) {
//        if (encoderState.lastA == 0 && currentA == 1) {
//            // A가 상승하는 에지일 때
//            if (currentB == 0) {
//                encoderState.pulseCount++;
//            } else {
//                encoderState.pulseCount--;
//            }
//        } else if (encoderState.lastA == 1 && currentA == 0) {
//            // A가 하강하는 에지일 때
//            if (currentB == 1) {
//                encoderState.pulseCount++;
//            } else {
//                encoderState.pulseCount--;
//            }
//        }
//        // 상태 업데이트
//        encoderState.lastA = currentA;
//        encoderState.lastB = currentB;
//    }
//}
//
//void controlMotor(float dutyCycle) {
//    // PWM 설정 (예: IfxGtm_Tom_PwmHl)
//    // dutyCycle은 0.0에서 1.0 사이의 값이어야 합니다.
//    IfxGtm_Tom_PwmHl_setOnTime(&g_GtmTomPwmHl.drivers.pwm, (uint32_t)(dutyCycle * IfxGtm_Tom_Timer_getPeriod(&g_GtmTomPwmHl.drivers.timer)));
//    IfxGtm_Tom_Timer_applyUpdate(&g_GtmTomPwmHl.drivers.timer);
//}
//
//typedef struct {
//    uint32 u32nuCnt1ms;
//    uint32 u32nuCnt10ms;
//    uint32 u32nuCnt100ms;
//    uint32 u32nuCnt50ms;
//    uint32 u32nuCnt500ms;
//    uint32 u32nuCnt1000ms;
//} TestCnt;
//
//TestCnt stTestCnt;
//float theta = 0, theta_old = 0, w = 0, w_old = 0, w_RPM = 0;
//float t = 0, Ts = 0.001;
//
//static void AppTask1ms(void) {
//    stTestCnt.u32nuCnt1ms++;
//    updateEncoder();  // 엔코더 업데이트 함수 호출
//
//    theta = (float)encoderState.pulseCount;  // 엔코더 펄스를 각도로 변환 (단순화)
//    w = (theta - theta_old) / Ts;
//    w_RPM = (w * 60) / (2 * 3.141592);
//    theta_old = theta;
//    w_old = w;
//
//    printf("Pulse Count: %d, w_RPM: %f\n", encoderState.pulseCount, w_RPM);
//}
//
//static void AppTask10ms(void) {
//    stTestCnt.u32nuCnt10ms++;
//}
//
//static void AppTask100ms(void) {
//    stTestCnt.u32nuCnt100ms++;
//}
//
//static void AppTask50ms(void) {
//}
//
//static void AppTask500ms(void) {
//    stTestCnt.u32nuCnt500ms++;
//}
//
//static void AppTask1000ms(void) {
//    stTestCnt.u32nuCnt1000ms++;
//    if (stTestCnt.u32nuCnt1000ms <= 5) {
//        g_GtmTomPwmHl.tOn[0] = 0.3; // 테스트를 위해 0.3으로 설정
//        g_GtmTomPwmHl.tOn[1] = 0.3; // 테스트를 위해 0.3으로 설정
//        GtmTomPwmHl_run();
//    } else if (stTestCnt.u32nuCnt1000ms > 5 && stTestCnt.u32nuCnt1000ms <= 10) {
//        g_GtmTomPwmHl.tOn[0] = 0.3;
//        g_GtmTomPwmHl.tOn[1] = 0.3;
//        GtmTomPwmHl_run();
//    } else {
//        g_GtmTomPwmHl.tOn[0] = 0.3; // 테스트를 위해 0.3으로 설정
//        g_GtmTomPwmHl.tOn[1] = 0.3; // 테스트를 위해 0.3으로 설정
//        GtmTomPwmHl_run();
//    }
//    printf("AppTask1000ms called\n");
//}
//
//void AppScheduling(void) {
//    if (stSchedulingInfo.u8nuScheduling1msFlag == 1u) {
//        stSchedulingInfo.u8nuScheduling1msFlag = 0u;
//        AppTask1ms();
//
//        if (stSchedulingInfo.u8nuScheduling10msFlag == 1u) {
//            stSchedulingInfo.u8nuScheduling10msFlag = 0u;
//            AppTask10ms();
//        }
//
//        if (stSchedulingInfo.u8nuScheduling100msFlag == 1u) {
//            stSchedulingInfo.u8nuScheduling100msFlag = 0u;
//            AppTask100ms();
//        }
//        if (stSchedulingInfo.u8nuScheduling50msFlag == 1u) {
//            stSchedulingInfo.u8nuScheduling50msFlag = 0u;
//            AppTask50ms();
//        }
//        if (stSchedulingInfo.u8nuScheduling500msFlag == 1u) {
//            stSchedulingInfo.u8nuScheduling500msFlag = 0u;
//            AppTask500ms();
//        }
//        if (stSchedulingInfo.u8nuScheduling1000msFlag == 1u) {
//            stSchedulingInfo.u8nuScheduling1000msFlag = 0u;
//            AppTask1000ms();
//        }
//    }
//}





