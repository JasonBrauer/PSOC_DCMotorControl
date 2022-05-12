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
#include <stdio.h>
#include <string.h>
#include "minunit.h"
#include "..\DCMotorControl.cydsn\dcmotor.h"

//command to run tests: gcc -o testdcmotor.exe testdcmotor.c ..\DCMotorControl.cydsn\dcmotor.c

//define tests_run which is declared globally in minunit.h
int tests_run = 0;


static char * concatIntComparison(
    char *functionName, 
    char *operator, 
    int value, 
    int expectedValue) {

    char strValue[10];
    sprintf(strValue, "%d", value);
    
    char strExpected[10];
    sprintf(strExpected, "%d", expectedValue);
    
    // cannot figure out why this char array mush be so large
    char message[200] = "";
    // why doesn't message need dereferenced here to get memory address?
    char *messagePtr = message;
    strcpy(message, functionName);
    strcat(message, " - calc failure: ");
    strcat(message, strValue);
    strcat(message, " !");
    strcat(message, operator);
    strcat(message, " ");
    strcat(message, strExpected);
    
    return messagePtr;
}


static char * testVoltFromSpeed() {
    mu_assert(concatIntComparison(
        "voltFromSpeed", 
        "==", 
        voltFromSpeed(7000, 14000, 8), 127), 
        voltFromSpeed(7000, 14000, 8) == 127
    );
    return 0;
}


static char * all_tests() {
    mu_run_test(testVoltFromSpeed);
    return 0;
}

int main(int argc, char **argv) {
    char *result = all_tests();
    if (result != 0) {
     printf("%s\n", result);
    }
    else {
     printf("ALL TESTS PASSED\n");
    }
    printf("Tests run: %d\n", tests_run);

    return result != 0;
 }

/* [] END OF FILE */
