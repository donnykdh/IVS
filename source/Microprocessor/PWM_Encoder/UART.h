/*
 * UART.h
 *
 *  Created on: 2024. 6. 27.
 *      Author: USER
 */

#ifndef UART_H_
#define UART_H_

#include "IfxAsclin_Asc.h"

extern IfxAsclin_Asc g_ascHancle3;

extern void _init_uart3(void);

extern void _out_uart3(const unsigned char str);
//static inline void _out_uart3(const unsigned char str) {
//    IfxAsclin_Asc_blockingWrite(&g_ascHandle3, str);
//}

extern void _out_uart3_INT(int num);

extern unsigned char _in_uart3(void);
#endif
