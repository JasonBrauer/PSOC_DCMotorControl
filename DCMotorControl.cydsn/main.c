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
#include "dcmotor.h"
#include "rotaryencoder.h"


/* Global variables */
volatile int input_speed = 0;

/**
*PSOC specific macro that wraps an Interrupt Service Routine function
*endcoder_interrupt is the ISR used to read a rotary encoder input
*@param encoder_interrupt (interrupt function name)
*
*/
CY_ISR(encoder_interrupt)
{
    uint8 encoder_status;
    // encoder_status reading as 0 or 2 instead of expected 1 or 3
    encoder_status = Status_Reg_1_Read();
    int increment = readEncoder((int)encoder_status);
    input_speed = adjustSpeed(input_speed, increment);
    Pin_12_4_ClearInterrupt();
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
    Sample_Hold_2_Start();
    isr_1_StartEx(encoder_interrupt);
    
    
    int16 v_supply_mv = 4500;
    int delay_count = 0;

    while(1)
    {   
        delay_count++;
        PWM_1_WriteCompare(input_speed);
        
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
            LCD_PrintString("speed_rpm:        ");
            LCD_Position(0,10);
            LCD_PrintNumber((uint16)speedFromBackEmf((int)back_emf_mv, 0.3466));
            
            LCD_Position(1,0);
            //              -0123456789012345- 16 char guide
            
            LCD_PrintString("input_speed:        ");
            LCD_Position(1,13);
            LCD_PrintNumber((uint16)input_speed);
        }
    }
}

/* [] END OF FILE */
