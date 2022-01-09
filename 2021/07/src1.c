#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "input.h"

int calcCost(int origin, int destination) 
{
    int cost;
    if(destination > origin) cost = destination - origin;
    else cost = origin - destination;

    return cost;
}

int main()
{


    int minPos = INT_MAX;
    int maxPos = INT_MIN;
    
    // Determine min and max crab position
    for(int i = 0; i < CRABS; i++) {
        if(input[i] > maxPos) maxPos = input[i];
        if(input[i] < minPos) minPos = input[i];
    }

    // Is it worth it, to just solve this naively?
    int bestCost = INT_MAX;
    int bestPos = minPos;
    int cost;
    for(int pos = bestPos; pos < maxPos; pos++) {
        cost = 0;
        // go over each crab and add the cost
        for(int crab = 0; crab < CRABS; crab++) {
            cost += calcCost(input[crab], pos);
        }
        if(cost < bestCost) {
            bestCost = cost;
            bestPos = pos;
        }
    }

    printf("The best calculated position to align the crabs is %d with a cost of %d\n", bestPos, bestCost);
    exit(EXIT_SUCCESS);
}

