#include <stdio.h>
#include "input.h"

int main() {
    int incs = 0;
    int* cur = &input[1];
    for(;*cur != 0; cur++) if(*cur > *(cur-1)) incs++;
    printf("Increments: %d\n", incs);
}