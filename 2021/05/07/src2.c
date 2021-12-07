#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "input.h"
//#include "input_test.h"

long long int calcCost(int origin, int destination) 
{
    long long int cost = 0;

    if(destination > origin) {
        //cost = ((destination + origin) / 2.0) * (destination - origin - 2);
        for(int i = 1; i < destination - origin + 1; i++) {
            cost += i;
        }
    }
    else {
        for(int i = 1; i < origin - destination + 1; i++) {
            cost += i;
        }
       //cost = ((destination + origin) / 2.0) * (origin - destination - 2);
    }
    printf("Moving from %d to %d costs %lld\n", origin, destination, cost);
    return ((long long int) cost);
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
    long long int bestCost = INT_MAX;
    int bestPos = minPos;
    long long int cost;
    for(int pos = bestPos; pos < maxPos; pos++) {
        cost = 0;
        // go over each crab and add the cost
        for(int crab = 0; crab < CRABS; crab++) {
            cost += calcCost(input[crab], pos);
        }
        if(cost < bestCost) {
            printf("Cost of position %d would be %lld which is better than best %lld\n", pos, cost, bestCost);
            bestCost = cost;
            bestPos = pos;
        } else {
            printf("Cost of position %d would be %lld which is worse than best %lld\n", pos, cost, bestCost);
        }
    }

    printf("The best calculated position to align the crabs is %d with a cost of %lld\n", bestPos, bestCost);
    exit(EXIT_SUCCESS);
}

