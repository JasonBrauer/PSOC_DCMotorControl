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
*Calculates the motor speed in rpm from back Emf and the motor speed constant
*@param backEmf an integer of the back emf in mV
*@param motorSpeedConstant a float of the motor speed constant in (mV / min^-1)
*
*returns integer speed in rpm
*/
int speedFromBackEmf(int backEmf, float motorSpeedConstant) 
{
    return((int)(backEmf / motorSpeedConstant)); 
};

/**
*Creates a voltage out signal based on motor speed
*@param currentSpeed an integer of current motor speed in rpm
*@param maxSpeed integer of the motor's max speed in rpm
*@param bitRange integer of num of bits for DAC input
*
*returns integer output to drive DAC signal
*/
int voltFromSpeed(
    int currentSpeed,
    int maxSpeed,
    int bitRange
)
{
    int maxOutput = bitRange ^ 2 - 1;
    float speedRatio = currentSpeed / maxSpeed;
    int outVolt = speedRatio * maxOutput;
    
    return outVolt;
};

/* [] END OF FILE */
