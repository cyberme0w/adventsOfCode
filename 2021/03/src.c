#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include "h.h"

int main() 
{
    if(LINES == 12) printf("Running small input\n");

    // PART 1

    // Initialize arrays for calculating the most common bit and gamma rate
    int ones[COLS], gamma[COLS];
    for(int i = 0; i < COLS; i++) {
        ones[i] = 0;
        gamma[i] = 0;
    }
    
    // Iterate over each col and line and fill the ones[] array
    for(int x = 0; x < COLS; x++) {
        for(int y = 0; y < LINES; y++) {
            if(input[y][x] == 1) ones[x]++;
        }
        // Calculate the gamma rate for the current column (x)
        if(ones[x] > LINES / 2) gamma[x] = 1;
    }
    int gammaValue = binToInt(gamma, COLS);
    
    // Print out the gamma rate
    printf("Gamma Rate: ");
    printArray(gamma, COLS);
    printf(" => %d\n", gammaValue);
     
    // Calculate the epsilon rate (inverted gamma rate)
    int eps[COLS];
    for(int i = 0; i < COLS; i++) {
        eps[i] = gamma[i] == 0 ? 1 : 0;
    }
    int epsilonValue = binToInt(eps, COLS);

    // Print out the epsilon rate
    printf("Epsilon Rate: ");
    printArray(eps, COLS);
    printf(" => %d\n", epsilonValue);

    // Calculate power consumption
    int power = gammaValue * epsilonValue;
    
    // Print out the power consumption
    printf("Power Consumption (Gamma Rate * Epsilon Rate): %d\n", power);



    // PART 2
    
    // Arrays for valid O2 and CO2 lines (initially all lines are valid)
    bool validOxyLines[LINES], validCo2Lines[LINES];
    for(int line = 0; line < LINES; line++) {
        validOxyLines[line] = true;
        validCo2Lines[line] = true;
    }
    long int validOxys = LINES;
    long int validCo2s = LINES;

    // Iterate over lines and filter out invalid O2 and CO2 lines
    for(int x = 0; x < COLS; x++) {
        // Calculate most and least common values
        int numZerosO2 = 0, numOnesO2 = 0, numZerosCO2 = 0, numOnesCO2 = 0;

        for(int y = 0; y < LINES; y++) {
            if(validOxyLines[y]) {
                if(input[y][x] == 0) numZerosO2++;
                else numOnesO2++;
            }
            if(validCo2Lines[y]) {
                if(input[y][x] == 0) numZerosCO2++;
                else numOnesCO2++;
            }
        }
        
        int mcv = numOnesO2 == numZerosO2 ? 1 : numOnesO2 > numZerosO2 ? 1 : 0;
        int lcv = numOnesCO2 == numZerosCO2 ? 0 : numOnesCO2 < numZerosCO2 ? 1 : 0;
        
        // Check each still valid oxy and co2 line until there is only one
        for(int y = 0; y < LINES; y++) {
            if(validOxys > 1 && validOxyLines[y]) {
                if(input[y][x] != mcv) {
                    validOxyLines[y] = false;
                    validOxys--;
                }
            }
            if(validCo2s > 1 && validCo2Lines[y]) {
                if(input[y][x] != lcv) {
                    validCo2Lines[y] = false;
                    validCo2s--;
                }
            }
        }
    }

    // Calculate CO2, O2 and Life Support ratings
    int co2Line, o2Line, co2Rating, o2Rating, lsr;
    for(int y = 0; y < LINES; y++) {
        if(validOxyLines[y]) {
            o2Rating = binToInt(input[y], COLS);
            o2Line = y;
        }
        if(validCo2Lines[y]) {
            co2Rating = binToInt(input[y], COLS);
            co2Line = y;
        }
    }
    lsr = co2Rating * o2Rating;

    // Print out ratings
    printf("Co2 Rating: ");
    printArray(input[co2Line], COLS);
    printf(" => %d\n", co2Rating);

    printf("O2 Rating: ");
    printArray(input[o2Line], COLS);
    printf(" => %d\n", o2Rating);

    printf("LSR: %d\n", lsr);
}

void printArray(int *array, int length) 
{
    for(int i = 0; i < length; i++) printf("%d", array[i]);
}

int binToInt(int array[], int len)
{
    int res = 0;
    for(int i=0; i<len; i++) res += (int) pow(2, i) * array[len - 1 - i];
    return res;
}
