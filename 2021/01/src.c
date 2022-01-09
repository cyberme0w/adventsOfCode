#include <stdio.h>
#include <stdbool.h>
#include "h.h"

int main()
{
    int incs_part1 = 0;
    int incs_part2 = 0;

    // Part 1
    int *cur = input + 1;
    for(;*cur != 0; cur++) {
        if(*cur > *(cur-1)) incs_part1++;
    }

    // Part 2
    cur = input + 1;
    for(;*(cur+2) != 0; cur++) {
        if(*(cur-1) + *cur + *(cur+1) < *(cur) + *(cur+1) + *(cur+2)) incs_part2++;
    }
    
    printf("Increments (pt1): %d\n", incs_part1);
    printf("Increments (pt2): %d\n", incs_part2);
}
