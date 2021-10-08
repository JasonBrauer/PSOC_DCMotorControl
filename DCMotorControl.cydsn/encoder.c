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
#include "string.h"

struct Output {
    int count;
    char direction[5];
};

static int readEncoder(int register_value)
{
    int increment = 0;
    if(register_value == 1) {
        increment = 1;
    }
        
    if(register_value == 2) {
        increment = -1;
    }
   
    return(increment);
    
};

static int adjustSpeed(int speed, int increment)
{
    int speed_increment = increment * 5;
    
    if(speed <= 250 && speed >= 5) {
        speed = speed + speed_increment;
        return(speed);
    }
    
    if(speed < 5 && speed_increment > 0) {
        speed = speed + speed_increment;
        return(speed);
    }
    
    speed = 0;
    return(speed);
    
    
};

static char* determineDirection(int channela, int channelb) 
{
    return("fwd");
};

static int calcCount(int channelb)
{
    return(1);
};
/* [] END OF FILE */
