#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "h.h"

//#define INPUT small_input
//#define INPUT_ROWS 10
#define INPUT input
#define INPUT_ROWS 200

void printInput(char *input[][14])
{
    for(int row = 0; row < INPUT_ROWS; row++)
    {
        printf("%.3d: ", row);

        for(int col = 0; col < 14; col++)
        {
            if(col < 10 || col > 10)
            {
                printf("%s ", input[row][col]);
            }
            else
            {
                printf("    %s", input[row][col]);
            }
        }

        printf("\n");
    }
}

int countUniqueDigits(char *input[][14])
{
    int count = 0;

    for(int row = 0; row < INPUT_ROWS; row++)
    {
        for(int col = 10; col < 14; col++)
        {
            int string_length = strlen(input[row][col]);
            
            if(string_length == 2 || string_length == 3 || string_length == 4 || string_length == 7)
            {
                count++;
            }
        }
    }
    
    return count;
}

int main()
{
    // Hi.
    printf("Advent of Code 2021: Day 08\n");

    // Print the test input.
    printInput(input);
    
    // Count how many unique digits there are in the output.
    int unique_digit_quantity;
    unique_digit_quantity = countUniqueDigits(INPUT);
    printf("There are %d unique digits in the output.\n", unique_digit_quantity);


    return(EXIT_SUCCESS);
}