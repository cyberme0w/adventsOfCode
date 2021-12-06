#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//#include "input_test.h"
#include "input.h"

void printArray(int *array, int length) {
    for(int i = 0; i < length; i++) {
        printf("%d", array[i]);
    }
    printf("\n");
}

int binToInt(int array[], int len)
{
    int res = 0;
    for(int i=0; i<len; i++) {
        res += (int) pow(2, i) * array[len - 1 - i];
    }
    return res;
}

int main()
{
    // Calculate life support rating (LSR) with following formula
    // LSR = O2Rating * CO2Rating
    
    // Declare oxy and co2 arrays
    int validOxyLines[LINES], validCo2Lines[LINES];
    long int ones, zeros;
       
    // Fill arrays
    for(int line = 0; line < LINES; line++) {
        validOxyLines[line] = 1;
        validCo2Lines[line] = 1;
    }
    long int validOxys = LINES;
    long int validCo2s = LINES;

    
    // O2
    for(int col = 0; col < COLS; col++) {
 
        // Calculate most common value
        zeros = 0;
        ones = 0;
        for(int _line = 0; _line < LINES; _line++) {
            if(validOxyLines[_line] == 1) {
                if(input[_line * COLS + col] == 0) zeros++;
                else ones++;
            }
        }
        int mcv;
        if(zeros == ones) { mcv = 2; }
        else if(zeros > ones) { mcv = 0; }
        else { mcv = 1; }
        
        // Check each line 
        for(int line = 0; line < LINES && validOxys > 1; line++) {
            
            // Check line only if it is valid 
            if(validOxyLines[line] == 1) {
                
                // Mark lines as valid/invalid depending on most common value
                if(( mcv == 2 && input[line * COLS + col] == 0)
                 ||( mcv == 0 && input[line * COLS + col] == 1)
                 ||( mcv == 1 && input[line * COLS + col] == 0)) {
                    validOxyLines[line] = 0;
                    validOxys--;
                    printf("O2: COL = %d    MCV = %d    CUR = %d    =>    Invalid\n", col, mcv, input[line * COLS + col]);
                }
            }
        }
    }
    
    printf("Valid Oxy lines:\n");
    printArray(validOxyLines, LINES);
    
    // Grab valid line and display as int 
    int validOxyLine = -1;
    int oxyRating = 0;
    for(int line = 0; line < LINES; line++) {
        if(validOxyLines[line] == 1) validOxyLine = line;
    }

    printf("Oxy Line: ");
    printArray(&input[validOxyLine * COLS], COLS); 
    oxyRating = binToInt(&input[validOxyLine * COLS], COLS);
    printf(" => %d\n", oxyRating);
    
            
    // CO2
    for(int col = 0; col < COLS; col++) {

        // Calculate most common value
        zeros = 0;
        ones = 0;
        for(int _line = 0; _line < LINES; _line++) {
            if(validCo2Lines[_line] == 1) {
                if(input[_line * COLS + col] == 0) zeros++;
                else ones++;
            }
        }
        int mcv;
        if(zeros == ones) { mcv = 2; }
        else if(zeros > ones) { mcv = 0; }
        else { mcv = 1; }

        // Check each line   
        for(int line = 0; line < LINES && validCo2s > 1; line++) {
            
            // Check if line is still valid and there are >1 valid lines
            if(validCo2Lines[line] == 1) {
                
                // Mark lines as valid/invalid depending on most common value
                if(( mcv == 2 && input[line * COLS + col] == 1)
                 ||( mcv == 0 && input[line * COLS + col] == 0)
                 ||( mcv == 1 && input[line * COLS + col] == 1)) {
                    validCo2Lines[line] = 0;
                    validCo2s--;
                    printf("CO2: COL = %d    MCV = %d    CUR = %d    =>    Invalid\n", col, mcv, input[line * COLS + col]);
                }
            }
        }
    }
    
    printf("Valid Co2 lines:\n");
    printArray(validCo2Lines, LINES);
    
    // Grab valid line and display as int 
    int validCo2Line = -1;
    int co2Rating = 0;
    for(int line = 0; line < LINES; line++) {
        if(validCo2Lines[line] == 1) validCo2Line = line;
    }

    printf("Co2 Line: ");
    printArray(&input[validCo2Line * COLS], COLS); 
    co2Rating = binToInt(&input[validCo2Line * COLS], COLS);
    printf(" => %d\n", co2Rating);

 


    // Calculate life support rating
    long int lifeSupportRate = oxyRating * co2Rating;
    printf("Life Support Rate (oxyR * co2R) = %ld\n", lifeSupportRate);
}
