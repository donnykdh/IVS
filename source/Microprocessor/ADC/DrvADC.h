/*
 * ADC.h
 *
 *  Created on: 2024. 6. 28.
 *      Author: USER
 */

#ifndef DRVADC_H
#define DRVADC_H


#include "Ifx_Types.h"
#include "UART.h"

typedef enum{
    ADC_GROUP0_CH0 = 0u,
    ADC_GROUP0_CH1,
    ADC_GROUP0_CH2,
    ADC_GROUP0_CH3,
    ADC_GROUP0_CH4,
    ADC_GROUP0_CH5,
    ADC_GROUP0_CH6,
    ADC_GROUP0_CH7,
    ADC_GROUP0_MAX,
}ADC_GROUP0;

typedef struct{
        uint32 UlSSense1_RAW;
        uint32 UlSSense2_RAW;
        uint32 UlSSense3_RAW;
}SensorAdcRaw;

extern SensorAdcRaw stSensorAdcRaw;

extern void DrvAdc_Group0Init(void);
extern void DrvAdc_GetAdcRawGroup0(void);

#endif
