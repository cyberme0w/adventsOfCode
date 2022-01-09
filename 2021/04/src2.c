#include <stdio.h>
#include <stdlib.h>
#include "input.h"
//#include "test_input.h"


// Register when a board has won
int boardHasWon[BOARDCOUNT];

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

int checkAllWinners() {
    int hor_count;
    int ver_count;

    // Go over each board that has not won yet   
    for(int boardno = 0; boardno < BOARDCOUNT; boardno++) {
        if(boardHasWon[boardno] == 0) {
            printf("Checking if board %d has won\n", boardno);

            // Go over each row and col and check for horizontal wins
            for(int row = 0; row < ROW; row++) {
                hor_count = 0; // reset
                for(int col = 0; col < COL; col++) {
                    if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 1) hor_count++;
                    if(hor_count == COL) {
                        boardHasWon[boardno] = 1;
                        return boardno;
                    }
                }
            }
    
            // Go over each col and row and check for vertical wins
            for(int col = 0; col < COL; col++) {
                ver_count = 0;
                for(int row = 0; row < ROW; row++) {
                    if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 1) ver_count++;
                    if(ver_count == ROW) {
                        boardHasWon[boardno] = 1;
                        return boardno;
                    }
                }
            }
        }
    }
    return -1;
}

int checkWinner(int boardno) {
    int hor_count;
    int ver_count;

    if(boardHasWon[boardno] == 0) {
        printf("Checking if board %d has won\n", boardno);

        // Go over each row and col and check for horizontal wins
        for(int row = 0; row < ROW; row++) {
            hor_count = 0; // reset
            for(int col = 0; col < COL; col++) {
                if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 1) hor_count++;
                if(hor_count == COL) {
                    boardHasWon[boardno] = 1;
                    return boardno;
                }
            }
        }
    
        // Go over each col and row and check for vertical wins
        for(int col = 0; col < COL; col++) {
            ver_count = 0;
            for(int row = 0; row < ROW; row++) {
                if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 1) ver_count++;
                if(ver_count == ROW) {
                    boardHasWon[boardno] = 1;
                    return boardno;
                }
            }
        }
    }
    return -1;
}

int calcPoints(int boardno, int lastNumCalled) {
    int points = 0;
    for(int row = 0; row < ROW; row++) {
        for(int col = 0; col < COL; col++) {
            if(boards_m[boardno * BOARDLENGTH + row * COL + col] == 0) {
                printf("  Points: adding %d to %d\n", 
                       boards[boardno * BOARDLENGTH + row * COL + col],
                       points
                );
                points += boards[boardno * BOARDLENGTH + row * COL + col];
                printf("  Points: new total %d\n", points);
            }
        }
    }
    return points * lastNumCalled;
}

int main() {
    // Init validity board
    for(int i = 0; i < BOARDCOUNT * BOARDLENGTH; i++) {
        boards_m[i] = 0;
    }
    
    // Init winner board log
    for(int i = 0; i < BOARDCOUNT; i++) {
        boardHasWon[i] = 0;
    }

    int boardsPlaying = BOARDCOUNT;

    // Pull all the numbers
    for(int pos = 0; pos < NUMLENGTH; pos++) {
        if(boardsPlaying > 0) {
            printf("There are still %d boards playing.\n", boardsPlaying);

            // pull next number and fill the boards
            int num = nums[pos];
    
            printf("Pulled number %d\n", num);
    
            // Check if any non-winning board has the number
            for(int board = 0; board < BOARDCOUNT; board++) {
                if(boardHasWon[board] == 0) {
                    printf("Checking if board %d has num %d\n", board, num);
                    for(int col = 0; col < COL; col++) {
                        for(int row = 0; row < ROW; row++) {
                            if(boards[board * BOARDLENGTH + row * ROW + col] == num) {
                                boards_m[board * BOARDLENGTH + row * ROW + col] = 1;
                            }    
                        }
                    }
                }

                // Check if board is winner
                if(checkWinner(board) != -1) {
                    boardsPlaying--;
                    printf("Board %d won the game by filling the last number (%d)\n", board, num);
                    printBoard(board);
    
                    // Calculate points
                    printf("Board %d has a total of %d points.\n", board, calcPoints(board, num));
                    if(boardsPlaying == 0) {
                        printf("Board %d was the last board to win.\n", board);
                        exit(EXIT_SUCCESS);
                    }
                }
            }
        }        
    }

    printf("After pulling all numbers, no winner was found. Here are the boards...\n");
    //printAllBoards();
    exit(EXIT_SUCCESS);
}
