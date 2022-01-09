#include <stdio.h>
#include "h.h"

int main() {
    int hor = 0, ver_1 = 0, ver_2 = 0, aim = 0;
    for(int i = 0; input[i] != STOP; i++) {
        if(input[i] == FWD) {
            i++;
            hor += input[i];
            ver_2 += aim * input[i];
        }
        else if(input[i] == DOWN) {
            i++;
            ver_1 += input[i];
            aim += input[i];
        }
        else if(input[i] == UP) {
            i++;
            ver_1 -= input[i];
            aim -= input[i];
        }
    }
    printf("Part 1 => hor: %d, ver: %d, mult: %d\n", hor, ver_1, hor * ver_1);
    printf("Part 2 => hor: %d, ver: %d, mult: %d\n", hor, ver_2, hor * ver_2);
}
