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
#include "dcmotor.h"

/**
*@param backEmf an integer of the back emf in mV
*@param motorSpeedConstant an integer of the motor speed constant in (mV / min^-1)
*
*returns integer speed in rpm
*/
int speedFromBackEmf(int backEmf, int motorSpeedConstant) {
    return(backEmf / motorSpeedConstant); 
};

/* [] END OF FILE */
