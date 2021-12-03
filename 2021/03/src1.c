#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input.h"

int main() 
{
    int ones[COLS];
    for(int i = 0; i < COLS; i++) ones[i] = 0;
    int gamma[] = {0,0,0,0,0,0,0,0,0,0,0,0};
    
    // calc col values across all lines
    for(int line = 0; line < LINES; line++) {
        for(int col = 0; col < COLS; col++) {
            if(input[(line - 1) * COLS + col] == 1) ones[col]++;
        }
    }
    
    // calc gamma
    printf("gamma: ");
    for(int col = 0; col < COLS; col++) {
        if(ones[col] > LINES / 2) gamma[col] = 1;
        printf("%d", gamma[col]);
    }
    int gammaInt = binToInt(gamma, COLS);
    printf("\n => %d\n", gammaInt);
     
    // calc epsilon from gamma
    int eps[] = {0,0,0,0,0,0,0,0,0,0,0,0};
    printf("epsilon: ");
    for(int i = 0; i < COLS; i++) {
        if(gamma[i] == 0) eps[i] = 1;
        else eps[i] = 0;
        printf("%d", eps[i]);
    }   
    int epsInt = binToInt(eps, COLS);
    printf("\n => %d\n", epsInt);
    
    // power consumption   
    int power;
    for(int i = 0; i < COLS; i++) {
        power = gammaInt * epsInt;
    }

    printf("power: %d\n", power);
    exit(EXIT_SUCCESS);
}

int binToInt(int array[], int len)
{
    int res = 0;
    for(int i=0; i<len; i++) {
        res += (int) pow(2, i) * array[len - 1 - i];
    }
    return res;
}
