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
#include "rotaryencoder.h"
#include "string.h"

struct Output {
    int count;
    char direction[5];
};


/**
*Determines an encrement based on a register value read from a rotary encoder
*@param register_value an integer of a status register value
*
*returns increment integer value of the increment 
*    either: -1, 1, 0 (default)
*/
int readEncoder(int register_value)
{
    int increment = 0;
    if(register_value == 0) {
        increment = 1;
    }
        
    if(register_value == 2) {
        increment = -1;
    }
   
    return(increment);
    
};

/**
*Adjusts an 8-bit period value for use with a PWM output driving motor speed
*@param speed integer current 8-bit period value
*@param increment integer -1, 1, 0 increment multiplier (multiplier is 5)
*
*returns speed new integer value for the 8-bit period 
*    either: -1, 1, 0 (default)
*/
int adjustSpeed(int speed, int increment)
{
    //int speed_increment = increment * 5;
    
    if(speed <= 250 && speed >= 5) {
        //speed = speed + speed_increment;
        if(increment == -1) {
            speed = speed - 5;
        }
        if (increment == 1) {
            speed = speed + 5;
        }
        return(speed);
    }
        
    if(speed > 250 && increment < 0) {
        speed = speed - 5;
        return(speed);
    }
    
    if(speed < 5 && increment > 0) {
        // speed = speed + speed_increment;
        speed = speed + 5;
        return(speed);
    }

    return(speed);

};
/* [] END OF FILE */
