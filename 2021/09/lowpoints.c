#include <stdio.h>
#include <stdlib.h>
//#include "lowpoints.h"
#include "lowpoints_test.h"

void printMap(int map[])
{
    for(int line = 0; line < HEIGHT; line++) {
        for(int col = 0; col < LENGTH; col++) {
            printf("%d", map[line * LENGTH + col]);
        }
        printf("\n");
    }
}

void calcLowpoint(int point)
{
    // point above
    if(point >= LENGTH && map[point - LENGTH] <= map[point]) lowpoints[point] = 0;

    // point below
    if(point <= LENGTH * HEIGHT - LENGTH && map[point + LENGTH] <= map[point]) lowpoints[point] = 0; 

    // point left of
    if(point % LENGTH > 0 && map[point - 1] <= map[point]) lowpoints[point] = 0;

    // point right of
    if(point % LENGTH < LENGTH - 1 && map[point + 1] <= map[point]) lowpoints[point] = 0;
}

int calcRisk(int map[], int lowpoints[])
{
    int totalRisk = 0;
    
    for(int point = 0; point < HEIGHT * LENGTH; point++) {
        if(lowpoints[point] == 1) {
            totalRisk += 1 + map[point];
        }
    }

    return totalRisk;
}

/*
Calculate the basin size by checking surroundings:
- check if they are valid (<9 and ==currentNumber + 1)
- check if the index is already mapped
Recursively calculate the basin size by checking surroundings, calculating their basin size, then adding the values
*/
int calcBasinSize(int point, int depth)
{
    int size = 0;
    char *indent = malloc((2*depth + 1) * sizeof(char));
    for(int i = 0; i < 2*depth; i++) {
        indent[i] = ' ';
    }
    indent[2*depth] = '\0';

    // Check Top 
    if((point >= LENGTH) && 
       (map[point - LENGTH] == (map[point] + 1)) && 
       (map[point - LENGTH] < 9)) {
        printf("%sP: %d top check...\n", indent, point);
        size += calcBasinSize(point-LENGTH, depth+1);
        printf("%sP: %d (%d), T: %d (%d) is valid -> size: %d\n", indent, point, map[point], point - LENGTH, map[point-LENGTH], size);
    }
    // Check Bot
    if((point <= (LENGTH * HEIGHT - LENGTH - 1)) && 
       (map[point + LENGTH] == (map[point] + 1)) &&
       (map[point + LENGTH] < 9)) {
        printf("%sP: %d bot check...\n", indent, point);
        size += calcBasinSize(point + LENGTH, depth+1);
        printf("%sP: %d (%d), B: %d (%d) is valid -> size: %d\n", indent, point, map[point], point + LENGTH, map[point+LENGTH], size);
    }
    // Check Left
    if((point % LENGTH > 0) && 
       (map[point - 1] == (map[point] + 1)) && 
       (map[point - 1] < 9)) {
        printf("%sP: %d left check...\n", indent, point);
        size += calcBasinSize(point - 1, depth+1);
        printf("%sP: %d (%d), L: %d (%d) is valid -> size: %d\n", indent, point, map[point], point - 1, map[point-1], size);
    }
    // Check Right
    if((point % LENGTH < LENGTH - 1) && 
       (map[point + 1] == (map[point] + 1)) && 
       (map[point + 1] < 9)) {
        printf("%sP: %d right check...\n", indent, point);
        size += calcBasinSize(point + 1, depth+1);
        printf("%sP: %d (%d), R: %d (%d) is valid -> size: %d\n", indent, point, map[point], point + 1, map[point+1], size);
    }

    printf("%sPoint %d has checked all neighbors. Returning size = %d + 1\n", indent, point, size);
    return size + 1;
}

// Alternative function for calculating basin sizes
int calcBasinSize2(int *map, int position, int *basinMap) {
    
    
}

int calcBasinSizeHelper() {}


int main()
{
    // setup lowpoint array
    for(int i = 0; i < LENGTH * HEIGHT; i++) {
        lowpoints[i] = 1;
    }

    // calculate lowpoints and add to array
    for(int i = 0; i < LENGTH * HEIGHT; i++) {
        calcLowpoint(i);
    }

    // (optional) print point map and lowpoints
    //printMap(lowpoints);
    //printf("\n");
    //printMap(map);

    // return results
    //printf("Total risk of map = %d\n", calcRisk(map, lowpoints));

    // Calculate basin for random point 
    //int pt = 115;
    //printf("First lowpoint (point = %d) = %d\n", pt, calcBasinSize(pt, 0));

    // CALCULATE BASIN SIZES

    // Reset top basin sizes
    int basinBigSizes[] = {0,0,0};

    // Go over each lowpoint, check basin size and add to top sizes
    for(int pos = 0; pos < HEIGHT * LENGTH; pos++) {
        if(lowpoints[pos] == 1) {
            // Reset Basin Map
            int basinMap[HEIGHT*LENGTH];
            for(int i = 0; i < HEIGHT * LENGTH; i++) {
                basinMap[i] = 0;
            }

            // Check neighbors for valid heights
            // Top

            // Bot

            // Left

            // Right

            // Go over basinMap and sum basin size
            int basinSize = 0;
            for(int i = 0; i < LENGTH * HEIGHT; i++) {
                if(basinMap[i] == 1) basinSize++;
            }

            // Check if basin size is big enough to be saved as top size
            
        }

    }

    // Calculate top 3 basin risks
    int basinRisk1 = 0;
    int basinRisk2 = 0;
    int basinRisk3 = 0;

    for(int i = 0; i < HEIGHT * LENGTH; i++) {
        if(lowpoints[i] == 1) {
            printf("\n\n\nPoint %d:\n", i);
            int cur_size = calcBasinSize(i, 0);
            if(cur_size > basinRisk3) {
                if(cur_size > basinRisk2) {
                    if(cur_size > basinRisk1) {
                        basinRisk3 = basinRisk2;
                        basinRisk2 = basinRisk1;
                        basinRisk1 = cur_size;
                    } else {
                        basinRisk3 = basinRisk2;
                        basinRisk2 = cur_size;
                    }
                } else {
                    basinRisk3 = cur_size;
                }
            }
        }
    }

    printf("Total basin size of 3 largest basins (%d, %d, %d) = %d\n", basinRisk1, basinRisk2, basinRisk3, (basinRisk1 * basinRisk2 * basinRisk3));
}
