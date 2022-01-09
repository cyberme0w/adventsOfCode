#include <stdio.h>
#include <stdlib.h>
#include "input.h"
//#include "test_input.h"

void printBoard(int boardno) {
    printf("Board #%d\n", boardno);
    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COL; col++) {
            printf("%d\t", boards[boardno * BOARDLENGTH + row * ROW + col]);
        }
        printf("\t\t");
        for(int col = 0; col < COL; col++) {
            printf("%d\t", boards_m[boardno * BOARDLENGTH + row * ROW + col]);
        }
        printf("\n");
    } 
    printf("\n");   
}

void printAllBoards() {
    for(int i = 0; i < BOARDCOUNT; i++) {
        printBoard(i);
    }
}

int checkWinner() {
    int hor_count;
    int ver_count;

    // Go over each board    
    for(int boardno = 0; boardno < BOARDCOUNT; boardno++) {
    
        // Go over each row and col and check for horizontal wins
        for(int row = 0; row < ROW; row++) {
            hor_count = 0; // reset
            for(int col = 0; col < COL; col++) {
                if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 1) hor_count++;
                if(hor_count == COL) return boardno;
            }
        }

        // Go over each col and row and check for vertical wins
        for(int col = 0; col < COL; col++) {
            ver_count = 0;
            for(int row = 0; row < ROW; row++) {
                if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 1) ver_count++;
                if(ver_count == ROW) return boardno;
            }
        }
    }
    return -1;
}

int calcPoints(int boardno, int lastNumCalled) {
    int points = 0;
    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COL; col++) {
            if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 0)
            points += boards[boardno * BOARDLENGTH + row * COL + col];
        }
    }
    return points * lastNumCalled;
}

int main() {
    // Init validity board
    for(int i = 0; i < BOARDCOUNT * BOARDLENGTH; i++) {
        boards_m[i] = 0;
    }

    // Check if BOARDCOUNT is right
    printf("Last Board Piece is %d\n", 
            boards[(BOARDCOUNT * BOARDLENGTH) - 1]
    );
    
    // Check if NUMLENGTH is right
    printf("Last num pulled is %d\n",
           nums[NUMLENGTH - 1]
    );


    // Check if print board is working
    for(int i = 0; i < BOARDCOUNT; i++) {
        printBoard(i);
    }

    // Pull all the numbers
    for(int pos = 0; pos < NUMLENGTH; pos++) {
        
        // pull next number and fill the boards
        int num = nums[pos];

        for(int board = 0; board < BOARDCOUNT; board++) {
            for(int col = 0; col < COL; col++) {
                for(int row = 0; row < ROW; row++) {
                
                    // Check if any board has the number
                    if(boards[board * BOARDLENGTH + row * ROW + col] == num) {
                        boards_m[board * BOARDLENGTH + row * ROW + col] = 1;
                    }    
                }
            }
        }

        // Check if there is a winner
        int winner = -1;
        winner = checkWinner();
        if(winner != -1) {
            printf("Board %d won the game by filling the last number (%d)\n", winner, num);
            printBoard(winner);

            // Calculate points
            printf("Board %d has a total of %d points.\n", winner, calcPoints(winner, num));
            exit(EXIT_SUCCESS);
        }
    }

    printf("After pulling all numbers, no winner was found. Here are the boards...\n");
    printAllBoards();
    exit(EXIT_SUCCESS);
}
