#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "h.h"

int main()
{
    // Initialize a 2D array representing the sea floor
    int map[MAXVAL][MAXVAL];
    for(int y = 0; y < MAXVAL; y++) {
        for(int x = 0; x < MAXVAL; x++) {
            map[y][x] = 0;
        }
    }

    // Read data into vent array
    Vent *v[ENTRIES];
    for(int i = 0; i < ENTRIES; i++) {
        v[i] = newVent(input[i][0], input[i][1], input[i][2], input[i][3]);
    }
    
    // Add the height of every non-diagonal vent to the map
    for(int i = 0; i < ENTRIES; i++) {
        // vertical vent
        if(v[i]->x1 == v[i]->x2 && v[i]->y1 != v[i]->y2) {
            int step = v[i]->y2 > v[i]->y1 ? 1 : -1;

            for(int y = v[i]->y1; y != v[i]->y2 + step; y += step) {
                map[y][v[i]->x1]++;
            }

        // horizontal vent
        } else if(v[i]->y1 == v[i]->y2 && v[i]->x1 != v[i]->x2) {
            int step = v[i]->x2 > v[i]->x1 ? 1 : -1;

            for(int x = v[i]->x1; x != v[i]->x2 + step; x += step) {
                map[v[i]->y1][x]++;
            }

        // diagonal vent
        } else if (CHECK_DIAGONAL) {
            // calculate x and y lengths of vent
            int len_x = v[i]->x1 > v[i]->x2 ? v[i]->x2 - v[i]->x1 : v[i]->x1 - v[i]->x2;
            int len_y = v[i]->y1 > v[i]->y2 ? v[i]->y2 - v[i]->y1 : v[i]->y1 - v[i]->y2;
            
            // check if lengths are same (-> angle is 45)
            if(abs(len_x) == abs(len_y)) {
                // calculate step directions
                int step_x = v[i]->x1 > v[i]->x2 ? -1 : 1;
                int step_y = v[i]->y1 > v[i]->y2 ? -1 : 1;

                // fill map with these steps
                int y = v[i]->y1;
                int x = v[i]->x1;
                while(y != v[i]->y2 + step_y) {
                    map[y][x]++;
                    y += step_y;
                    x += step_x;
                }
            }
        }
    }

    // Print the map to check how it looks - good for debugging with small map
    //printMap(map);

    // Calculate how many dangerous (>2) spots there are in the map
    printf("There are %d dangerous spots in the map!\n", countOverlaps(map));

    // Cleanup :D
    deleteVents(v);
}

Vent *newVent(int x1, int y1, int x2, int y2)
{
    Vent *v = malloc(sizeof(Vent));
    v->x1 = x1;
    v->y1 = y1;
    v->x2 = x2;
    v->y2 = y2;
    v->isDiagonal = !(x1 == x2 || y1 == y2);
    return v;
}

void deleteVents(Vent *vents[])
{
    for(int i = 0; i < ENTRIES; i++) {
        free(vents[i]);
    }
}

void printMap(int map[MAXVAL][MAXVAL])
{
    for(int y = 0; y < MAXVAL; y++) {
        for(int x = 0; x < MAXVAL; x++) {
            printf("%d", map[y][x]);
        }
        printf("\n");
    }
    printf("\n");
}

int countOverlaps(int map[MAXVAL][MAXVAL])
{
    int overlaps = 0;
    for(int y = 0; y < MAXVAL; y++) {
        for(int x = 0; x < MAXVAL; x++) {
            if(map[y][x] >= 2) overlaps++;
        }
    }
    return overlaps;
}
