#include <stdio.h>
#include "input.h"

int main() {
    int incs = 0;
    int* cur = &input[1];
    for(;*(cur+2) != 0; cur++) {
        if(*(cur-1) + *cur + *(cur+1) < *(cur) + *(cur+1) + *(cur+2)) incs++;
    }
    printf("Increments: %d\n", incs);
}