#ifndef __LOWPOINTS_H__
#define __LOWPOINTS_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 10
#define HEIGHT 5

void printLowpoints(int map[]);
void calcLowpoint(int point);
int calcRisk(int map[], int lowpoints[]);



int lowpoints[LENGTH * HEIGHT];

int map[] = {
2,1,9,9,9,4,3,2,1,0,
3,9,8,7,8,9,4,9,2,1,
9,8,5,6,7,8,9,8,9,2,
8,7,6,7,8,9,6,7,8,9,
9,8,9,9,9,6,5,6,7,8
};
#endif // lowpoints.h
