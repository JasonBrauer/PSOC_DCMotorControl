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

    while(1)
    {   
        int speeds[] = {0, 32, 64, 128, 192, 255};
        int speed_size = sizeof(speeds) / sizeof(speeds[0]);
        for(int i=0; i < speed_size; i++) {
            PWM_1_WriteCompare(speeds[i]);
            CyDelay(3000);
        }
    }
}

/* [] END OF FILE */
