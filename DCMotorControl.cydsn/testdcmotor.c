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
#include "dcmotor.h"

//define tests_run which is declared globally in minunit.h
int tests_run = 0;


static char * concatIntInequality(char *functionName, int value, int expectedValue) {
    char *strValue;
    sprintf(strValue, "%d", value);
    
    char *strExpected;
    sprintf(strExpected, "%d", expectedValue);
    
    strcat(functionName, " - calc failure: ");
    strcat(functionName, strValue);
    strcat(functionName, " != ");
    strcat(functionName, strExpected);
    
    printf(functionName);
    
    return functionName;
}


static char * testVoltFromSpeed() {
    mu_assert(concatIntInequality("voltFromSpeed", voltFromSpeed(7000, 14000, 8),127), voltFromSpeed(7000, 14000, 8) == 127);
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
