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
#include "backemf.h"

/*
Calculates the speed of a motor from the motor's speed constand and back_emf

Inputs
------
velocity_constant float: velocity of back emf constant of the motor in mV / min^-1 (rotations, not rad) 

back_emf: the current back_emf produced by the motor in mV

returns
-------
speed int: speed of the motor in rpm
*/
int speedFromBackEmf(float velocity_constant, float back_emf) 
{
    return((int)(back_emf / velocity_constant));
};
    

/* [] END OF FILE */
