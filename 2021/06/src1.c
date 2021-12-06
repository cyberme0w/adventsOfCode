#include <stdio.h>
#include <stdlib.h>
#include "input.h"
//#include "input_test.h"

#define AGEGROUPS 9
#define DAYS 80

long long int fishAge[AGEGROUPS];
long long int fishAgeAfter[AGEGROUPS];

void printArray(long long int *array) {
    for(int i = 0; i < AGEGROUPS; i++) {
        printf("%lld ", array[i]);
    }
    printf("\n");
}

int main() 
{
    // init fish groups
    for(int i = 0; i < AGEGROUPS; i++) {
        fishAge[i] = 0;
        fishAgeAfter[i] = 0;
    }
    printf("fishAge = ");
    printArray(fishAge);
    printf("\n");
    printf("fishAgeAfter = ");
    printArray(fishAgeAfter);
    printf("\n");
   

    // read from input into fishAge groups
    for(int i = 0; i < INPUTLENGTH; i++) {
        fishAge[input[i]]++;
    }

    printf("fishAge after input = ");
    printArray(fishAge);
    printf("\n");
    
    for(int day = 0; day < DAYS; day++) {
        // age fish
        for(int i = 0; i < 8; i++) {
            fishAgeAfter[i] = fishAge[i+1];
        }

        // new fish get born and old get added to 6
        fishAgeAfter[8] = fishAge[0];
        fishAgeAfter[6] += fishAge[0];
        
        // move one array to the other and print quantities
        for(int i = 0; i < 9; i++) {
            fishAge[i] = fishAgeAfter[i];
            fishAgeAfter[i] = 0;
        }
        
        printf("Day %d\n:", day);
        printArray(fishAge);
    }

    int total = 0;
    for(int i = 0; i < AGEGROUPS; i++) {
        total += fishAge[i];
    }
        
    printf("After %d days, there would be %d lanternfish.\n", DAYS, total);
    exit(EXIT_SUCCESS);
}
