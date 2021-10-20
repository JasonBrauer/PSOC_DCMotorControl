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
#include "rotaryencoder.h"

/*******************************************************************************
* Function Name: encoder_interrupt
********************************************************************************
*
* Summary:
*  Handles the Interrupt Service Routine for the WDT timer.
*
*******************************************************************************/
volatile int input_speed = 0;


CY_ISR(encoder_interrupt)
{
    uint8 encoder_status;
    // encoder_status reading as 0 or 2 instead of expected 1 or 3
    encoder_status = Status_Reg_1_Read();
    int increment = readEncoder((int)encoder_status);
    input_speed = adjustSpeed(input_speed, increment);
}


int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    PWM_1_Start();
    AMux_1_Start();
    ADC_DelSig_1_Start();
    LCD_Start();
    Comp_1_Start();
    Comp_2_Start();
    Comp_1_ZeroCal();
    Comp_2_ZeroCal();
    Sample_Hold_1_Start();
    isr_1_StartEx(encoder_interrupt);
    
    
    int16 v_supply_mv = 4500;
    while(1)
    {   
        int speeds[] = {0, 32, 64, 128, 192, 255};
        int speed_size = sizeof(speeds) / sizeof(speeds[0]);
        for(int i=0; i < speed_size; i++) {
            PWM_1_WriteCompare(speeds[i]);
            int delay_total = 3000;
            /* everything inside for loop will run 'during' total delay */
            for(int delay_count=0; delay_count <= delay_total; delay_count++) {
                CyDelay(1); // Delay 1 millisecond
                /* Break into speed calc function later */
                /* Calc speed between each delay request */
                Control_Reg_1_Write(1);
                CyDelayUs(200);
                AMux_1_Select(0);
                ADC_DelSig_1_StartConvert();
                ADC_DelSig_1_IsEndConversion(ADC_DelSig_1_WAIT_FOR_RESULT);
                CyDelayUs(5); // add delay for conversion to complete
                Control_Reg_1_Write(0);
                int32 back_emf_counts = (int32)ADC_DelSig_1_GetResult16();
                int16 back_emf_mv = v_supply_mv - ADC_DelSig_1_CountsTo_mVolts(back_emf_counts);
                /* only write to LCD every 100 loops (100 ms) */
                if(delay_count % 500 == 0) {
                    LCD_Position(0,0);
                    //              -0123456789012345- 16 char guide
                    LCD_PrintString("b_emf_mv:        ");
                    LCD_Position(0,10);
                    LCD_PrintNumber((uint16)back_emf_mv);
                    
                    LCD_Position(1,0);
                    //              -0123456789012345- 16 char guide
                    LCD_PrintString("input_speed:        ");
                    LCD_Position(1,13);
                    LCD_PrintNumber((uint16)input_speed);
            
                }
                /* longer motor off delay for scope inspection 
                if(delay_count % 500 == 0) {
                    Control_Reg_1_Write(1);
                    CyDelay(10);
                    Control_Reg_1_Write(0);
                }
                */
            }
        }
    }
}

/* [] END OF FILE */
