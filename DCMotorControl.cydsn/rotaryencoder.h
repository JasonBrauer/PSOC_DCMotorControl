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
#ifndef ENCODER_H
#define ENCODER_H

struct output {
    int count;
    char direction[5];
};

int readEncoder(int);

int adjustSpeed(int, int);

#endif

/* [] END OF FILE */
