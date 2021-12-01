#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main()
{
    int res, i = 0;
    for(;res!=-1;input++) {
        i++;
        if(*input=='(') res++;
        else res--;
    }
    printf("%d\n", i);
}
