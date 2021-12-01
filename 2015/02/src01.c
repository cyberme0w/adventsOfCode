#include <stdio.h>
#include <stdlib.h>
#include "input.h"

int main()
{
    int* ptr = input;
    int feet2 = 0;
    for(;*ptr!=0;ptr+=3) {
        int l = *ptr;
        int w = *(ptr+1);
        int h = *(ptr+2);
        int min=l*w;
        if(l*h<min) min=l*h;
        if(w*h<min) min=w*h;
        feet2+=2*l*w+2*w*h+2*h*l+min;
    }
    printf("%d\n", feet2);
}


