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
