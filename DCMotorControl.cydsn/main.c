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
        int speeds[] = {0, 32, 64, 128, 192, 255};
        int speed_size = sizeof(speeds) / sizeof(speeds[0]);
        for(int i=0; i < speed_size; i++) {
            PWM_1_WriteCompare(speeds[i]);
            int delay_total = 3000;
            /* everything inside for loop will run 'during' total delay */
            for(int delay_count=0; i <= delay_total; i++) {
                CyDelay(1); // Delay 1 millisecond
                /* Break into speed calc function later */
                /* Calc speed between each delay request */
                AMux_1_Select(1);
                ADC_DelSig_1_StartConvert();
                ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);
                CyDelay(1000); // wait 100 microsec for conversion - IsEndConversion not working
                uint16 Back_EMF_Counts = ADC_DelSig_1_GetResult16();
                int16 Back_EMF_mV = ADC_DelSig_1_CountsTo_mVolts(Back_EMF_Counts);
            }
        }
    }
}

/* [] END OF FILE */
