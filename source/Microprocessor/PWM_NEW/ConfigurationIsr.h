/*
 * ConfigurationIsr.h
 *
 *  Created on: 2024. 6. 28.
 *      Author: USER
 */

#ifndef CONFIGURATIONISR_H
#define CONFIGURATIONISR_H

#define ISR_ASSIGN(no, cpu)     ((no << 8) + cpu)
#define ISR_PRIORITY(no_cpu)    (no_cpu >> 8)
#define ISR_PROVIDER(no_cpu)    (no_cpu % 8)

#define ISR_PRIORITY_TIMER      150
#define ISR_PROVIDER_TIMER      IfxSrc_Tos_cpu0
#define INTERRUPT_TIMER         ISR_ASSIGN(ISR_PRIORITY_TIMER, ISR_PROVIDER_TIMER)

#endif
