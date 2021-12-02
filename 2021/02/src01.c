#include <stdio.h>
#include "input.h"

int main() {
    int hor, ver = 0;
    for(int i = 0; input[i] != -1337; i++) {
        if(input[i] == -1) hor += input[++i];
        else if(input[i] == -2) ver += input[++i];
        else if(input[i] == -3) ver -= input[++i];
    }
    printf("hor: %d, ver: %d, mult: %d\n", hor, ver, hor * ver);
}