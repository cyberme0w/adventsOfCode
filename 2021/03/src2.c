#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "input_test.h"
//#include "input.h"

void printValidArray(int *array, int length) {
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
    int validOxyLines[LINES], validCo2Lines[LINES], ones[COLS], zeros[COLS];
    int mcv[COLS];
    
    for(int col = 0; col < COLS; col++) {
        ones[col] = 0;
        zeros[col] = 0;
    }

    // Fill arrays
    for(int line = 0; line < LINES; line++) {
        validOxyLines[line] = 1;
        validCo2Lines[line] = 1;

        // use same loop to calculate the most common value (count ones)
        for(int col = 0; col < COLS; col++) {
            if(input[line * COLS + col] == 1) ones[col]++;
            if(input[line * COLS + col] == 0) zeros[col]++;
        }
    }
    
    // Show the most common values
    printf("Most common values:\n");
    for(int col = 0; col < COLS; col++) {
        printf("ones[%d] = %d, zeros[%d] = %d\n", col, ones[col], col, zeros[col]);
        if(ones[col] == zeros[col]) {
            printf("!!!mcv[%d] = 2\n", col);
            mcv[col] = 2;
        } else if(ones[col] > (LINES/2)) {
            mcv[col] = 1;
        } else {
            mcv[col] = 0;
        }
        printf("%d", mcv[col]);
    }
    printf("\n");

    // O2
    int validOxys = LINES;

    // Filter out invalid oxy entries
    for(int col = 0; col < COLS; col++) {
        for(int line = 0; line < LINES && validOxys > 1; line++) {
            // Ignore line if already invalid
            if(validOxyLines[line] != 0) {

                // Grab current input value
                int cur = input[line * COLS + col];
                printf("\ncur = %d\n", cur);
                printf("mcv[%d] = %d\n", col, mcv[col]);
                
                // Check for validity (if ones = zeros, then keep 1 lines; otherwise keep mcv lines)
                if((mcv[col] == 2 && cur == 0) || 
                   (mcv[col] != 2 && cur != mcv[col])) 
                {
                    validOxyLines[line] = 0;
                    validOxys--;
                    printf("  O2: Invalidated line %d. %d lines remaind valid.\n", line, validOxys);
                    printValidArray(validOxyLines, LINES);
                }
            }
        }
    }

    // CO2
    int validCo2s = LINES;

    // Filter out invalid co2 entries
    for(int col = 0; col < COLS; col++) {
        for(int line = 0; line < LINES && validCo2s > 1; line++) {

            // Ignore line if already invalid
            if(validCo2Lines[line] != 0) {
                // Grab current input value
                int cur = input[line * COLS + col];

                // Check for validity (if ones = zeros, then keep 0 lines; otherwise keep mcv lines)
                if((mcv[col] == 2 && cur == 1) || 
                   (mcv[col] != 2 && cur == mcv[col])) 
                {
                    validCo2Lines[line] = 0;
                    validCo2s--;
                    printf("CO2: Invalidated line %d. %d lines remaind valid.\n", line, validCo2s);
                    printValidArray(validCo2Lines, LINES);
                }
            }
        }
    }


  
    printf("validOxys: %d\n", validOxys);
    printf("validCo2s: %d\n", validCo2s);
 
    // Print out valid arrays
    printf("Valid oxy array:\n");
    for(int i = 0; i < LINES; i++) printf("%d", validOxyLines[i]);
    
    printf("\nValid co2 array:\n");
    for(int i = 0; i < LINES; i++) printf("%d", validCo2Lines[i]);
    printf("\n");

    // Grab the valid line
    int validOxyEntryLine = 0;
    int validCo2EntryLine = 0;

    for(int line = 0; line < LINES; line++) {
        if(validOxyLines[line] == 1) {
            validOxyEntryLine = line;
            break;
        }
    }
    
    printf("valid oxy line = %d\n", validOxyEntryLine);

    for(int line = 0; line < LINES; line++) {
        if(validCo2Lines[line] == 1) {
            validCo2EntryLine = line;
            break;
        }
    }
    
    printf("valid co2 line = %d\n", validCo2EntryLine);

    int oxyRating = binToInt(&input[validOxyEntryLine * COLS], COLS);
    int co2Rating = binToInt(&input[validCo2EntryLine * COLS], COLS);

    printf("Oxy Entry Line: ");
    printValidArray(&input[validOxyEntryLine * COLS], COLS);
    printf("Co2 Entry Line: ");
    printValidArray(&input[validCo2EntryLine * COLS], COLS);

    printf("Life Support Rating = %d * %d = %d\n", oxyRating, co2Rating, oxyRating * co2Rating);    
}
