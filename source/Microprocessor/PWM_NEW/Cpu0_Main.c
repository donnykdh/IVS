#include "Ifx_Types.h"
#include "IfxCpu.h"
#include "IfxScuWdt.h"
#include "AppScheduling.h"
#include "Driver_Stm.h"
#include <stdio.h>

IfxCpu_syncEvent g_cpuSyncEvent = 0;

void core0_main(void)
{
    IfxCpu_enableInterrupts();
    
    /* !!WATCHDOG0 AND SAFETY WATCHDOG ARE DISABLED HERE!!
     * Enable the watchdogs and service them periodically if it is required
     */
    IfxScuWdt_disableCpuWatchdog(IfxScuWdt_getCpuWatchdogPassword());
    IfxScuWdt_disableSafetyWatchdog(IfxScuWdt_getSafetyWatchdogPassword());
    
    /* Wait for CPU sync event */
    IfxCpu_emitEvent(&g_cpuSyncEvent);
    IfxCpu_waitEvent(&g_cpuSyncEvent, 1);


    Driver_Stm_Init();
    //printf("Driver_Stm_Init called\n");
    GtmTomPwmHl_init();
    //printf("GtmTomPwmHl_init called\n");
    //_init_uart3();

        
    while(1)
    {

        AppScheduling();
//        g_GtmTomPwmHl.tOn[0] = 0.3;
//        g_GtmTomPwmHl.tOn[1] = 0.3;
        //printf("AppScheduling called\n");
    }
}
