#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main()
{
    char* ptr = input;
    int res = 0;
    for(;*input!=0;input++) {
        if(*input=='(') res++;
        else res--;
    }
    printf("%d\n", res);
}
