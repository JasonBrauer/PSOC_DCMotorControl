/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include "project.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();
    AMux_1_Start();
    ADC_DelSig_1_Start();

    while(1)
    {   
        AMux_1_Select(1);
        int speeds[] = {0, 32, 64, 128, 192, 255};
        int speed_size = sizeof(speeds) / sizeof(speeds[0]);
        for(int i=0; i < speed_size; i++) {
            PWM_1_WriteCompare(speeds[i]);
            int delay_total = 3000;
            /* Break into speed calc function later */
            /* Calc speed between each delay request */
            for(int delay_count=0; i <= delay_total; i++) {
                CyDelay(1); // Delay 1 millisecond
            }
        }
    }
}

/* [] END OF FILE */
