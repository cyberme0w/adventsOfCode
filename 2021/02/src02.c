#include <stdio.h>
#include "input.h"

int main() {
    int hor, ver, aim = 0;
    for(int i = 0; input[i] != -1337; i++) {
        if(input[i] == -1) {
            i++;
            hor += input[i];
            ver += aim * input[i];
        }
        else if(input[i] == -2) aim += input[++i];
        else if(input[i] == -3) aim -= input[++i];
    }
    printf("hor: %d, ver: %d, mult: %d\n", hor, ver, hor*ver);
}