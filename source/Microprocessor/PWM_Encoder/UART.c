/*
 * UART.c
 *
 *  Created on: 2024. 6. 27.
 *      Author: USER
 */

#include "IfxAsclin_Asc.h"
#include "IfxCpu_Irq.h"
#include <stdio.h>
#include <string.h>
#include "IfxStdIf_DPipe.h"
#include "isr_priority.h"

// 버퍼 크기 및 보드레이트 정의
#define ASC_TX_BUFFER_SIZE 256
#define ASC_RX_BUFFER_SIZE 256
#define ASC_BAUDRATE 115200
#define TOF_BAUDRATE 921600
#define BLUETOOTH_BAUDRATE 9600

// 표준 인터페이스 객체
//static IfxAsclin_Asc g_ascHandle0;
//static IfxAsclin_Asc g_ascHandle1;
static IfxAsclin_Asc g_ascHandle3;
static IfxStdIf_DPipe g_ascStandardInterface;

// 데이터 및 FIFO 런타임 변수를 위한 전송 버퍼
uint8 g_uartTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];

IFX_INTERRUPT(asclin3TxISR, 0, ISR_PRIORITY_ASCLIN_TX);
void asclin3TxISR(void)
{
    IfxAsclin_Asc_isrTransmit(&g_ascHandle3);
}

IFX_INTERRUPT(asclin3RxISR, 0, ISR_PRIORITY_ASCLIN_RX);
void asclin3RxISR(void)
{
    IfxAsclin_Asc_isrReceive(&g_ascHandle3);
}

IFX_INTERRUPT(asclin3ErrISR, 0, ISR_PRIORITY_ASCLIN_ER);
void asclin3ErrISR(void)
{
    IfxAsclin_Asc_isrError(&g_ascHandle3);
}

void _init_uart3(void)
{
    IfxAsclin_Asc_Config ascConf;
    IfxAsclin_Asc_initModuleConfig(&ascConf, &MODULE_ASCLIN3);

    // 원하는 보드레이트 설정
    ascConf.baudrate.baudrate = ASC_BAUDRATE;
    ascConf.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;

    // 샘플링 모드 설정
    ascConf.bitTiming.medianFilter = IfxAsclin_SamplesPerBit_three;
    ascConf.bitTiming.samplePointPosition = IfxAsclin_SamplePointPosition_8;

    // ISR 우선순위 및 인터럽트 타겟 설정
    ascConf.interrupt.txPriority = ISR_PRIORITY_ASCLIN_TX;
    ascConf.interrupt.rxPriority = ISR_PRIORITY_ASCLIN_RX;
    ascConf.interrupt.erPriority = ISR_PRIORITY_ASCLIN_ER;
    ascConf.interrupt.typeOfService = IfxSrc_Tos_cpu0;

    // 핀 설정
    const IfxAsclin_Asc_Pins pins = {
        .cts = NULL_PTR, // CTS 핀 사용 안 함
        .ctsMode = IfxPort_InputMode_pullUp,
        .rx = &IfxAsclin3_RXD_P32_2_IN, // RX 핀
        .rxMode = IfxPort_InputMode_pullUp,
        .rts = NULL_PTR, // RTS 핀 사용 안 함
        .tx = &IfxAsclin3_TX_P15_7_OUT, // TX 핀
        .txMode = IfxPort_OutputMode_pushPull,
        .pinDriver = IfxPort_PadDriver_cmosAutomotiveSpeed1
    };
    ascConf.pins = &pins;

    /* FIFO 버퍼 설정 */
    ascConf.txBuffer = g_uartTxBuffer;
    ascConf.txBufferSize = ASC_TX_BUFFER_SIZE;
    ascConf.rxBuffer = g_uartRxBuffer;
    ascConf.rxBufferSize = ASC_RX_BUFFER_SIZE;

    /* ASCLIN 모듈 초기화 */
    IfxAsclin_Asc_initModule(&g_ascHandle3, &ascConf);

    /* 표준 인터페이스 초기화 */
    IfxAsclin_Asc_stdIfDPipeInit(&g_ascStandardInterface, &g_ascHandle3);

    /* 콘솔 초기화 */
    //Ifx_Console_init(&g_ascStandardInterface);
}


void _out_uart3(const unsigned char chr)
{
    while (IfxAsclin_Asc_canWriteCount(&g_ascHandle3, 1, TIME_INFINITE) != TRUE);
    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, chr);
}



void _out_uart3_INT(int num)
{
    char buffer[50];
    sprintf(buffer, "%d", num); // int 값을 문자열로 변환

    for (int i = 0; i < strlen(buffer); i++) {
        while (IfxAsclin_Asc_canWriteCount(&g_ascHandle3, 1, TIME_INFINITE) != TRUE);
        IfxAsclin_Asc_blockingWrite(&g_ascHandle3, (unsigned char)buffer[i]);
    }

}


/* 시리얼 라인에서 문자를 수신 (대기) */
unsigned char _in_uart3(void)
{
    return IfxAsclin_Asc_blockingRead(&g_ascHandle3);
}

