#define LINES 1000
#define COLS 12

int binToInt(int array[], int len);

int input[] = {
0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0,
0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1,
1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0,
1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0,
0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1,
0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0,
0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1,
1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0,
1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1,
0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1,
1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0,
1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1,
0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1,
0, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 1,
1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0,
0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0,
1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0,
1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0,
1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1,
0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1,
0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1,
1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1,
0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0,
1, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1,
1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1,
1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0,
0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1,
1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0,
1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0,
0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0,
0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0,
1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1,
1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0,
1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1,
0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0,
1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0,
1, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1,
0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0,
0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0,
0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0,
1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0,
0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0,
1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0,
1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1,
1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1,
1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,
1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1,
1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0,
0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1,
0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0,
0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0,
1, 0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1,
1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1,
1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0,
1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1,
1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0,
1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
0, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0,
1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1,
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1,
0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0,
1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1,
0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 1,
1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0,
1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1,
0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0,
1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0,
1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0,
0, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0,
0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1,
0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0,
1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0,
0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1,
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1,
0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0,
1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1,
1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0, 0,
1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 1,
1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0,
0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0,
1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0,
1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1,
0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1,
1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0,
1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0,
1, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1,
0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1,
1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0,
1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1,
1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1,
0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0,
1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0,
1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1,
0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1,
1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1,
0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0,
0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0,
1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1,
0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1,
0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0,
0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0,
0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0,
0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1,
1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1,
1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1,
1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1,
0, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0,
0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0,
1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0,
0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
0, 0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 1,
0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1,
1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1,
0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1,
0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1,
0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1,
1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1,
0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1,
0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1,
0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1,
1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1,
0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0,
1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1,
0, 1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0,
1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0,
1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0,
0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0,
0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 0,
1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1,
1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0,
1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0,
1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0,
1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1,
1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1,
0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1,
0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0, 1,
1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0,
1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0,
1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1,
0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1,
0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0,
0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0,
0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0,
0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0,
1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1,
0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1,
0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1,
1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1, 1,
0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1,
0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1,
0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0,
0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0,
1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0,
1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1,
0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0,
1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1,
1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1,
0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0,
1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1,
1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1,
0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0,
1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1,
0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 0,
1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 0,
1, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1,
0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0,
1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1,
0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0,
1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1,
0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1,
0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1,
1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1,
1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1,
1, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1,
1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0,
0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0,
1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1,
1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1,
0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0,
0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0,
1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1,
0, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0,
0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1, 1,
0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0,
0, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0,
0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1,
1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0,
1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1,
0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0,
0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1,
1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1,
1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1,
0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0,
0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0,
1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0,
0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0,
0, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1,
0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1,
0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1,
1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1,
0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0,
0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0, 0,
1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0,
0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1,
0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0,
1, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0,
0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1,
1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0,
1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1,
1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1,
1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1,
0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1,
0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1,
0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1,
1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1,
0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1,
0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0,
1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1,
0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0,
0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1,
0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1,
1, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1,
0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1,
1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1, 1,
1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1,
0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1,
1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1,
0, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0,
0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0,
1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 0,
1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1,
0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1,
1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1,
0, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0,
0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0,
1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1,
0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0,
0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1,
0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0,
1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0,
1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0,
0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1,
0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1,
1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1,
0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1, 0,
0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1,
0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0,
0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0,
1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1,
0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1,
1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0,
1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1,
1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1, 0,
0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0,
0, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1,
1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1,
1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0,
1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0,
1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1,
1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0,
0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0,
0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1,
0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1,
0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0,
0, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1,
1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0,
1, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0,
0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0,
1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0,
1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0,
0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 0,
1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1,
0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0,
0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0,
1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 1,
1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0,
1, 0, 1, 0, 1, 1, 1, 1, 0, 1, 0, 1,
1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0,
1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0,
1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1,
1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1,
1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0,
1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1,
1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 0,
0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1,
1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0,
0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0,
0, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1,
0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1,
1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0,
1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 1,
1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1,
1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0,
1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 1, 1,
0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0,
1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0,
1, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 0,
1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0,
0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1,
0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1,
1, 1, 0, 1, 1, 0, 0, 0, 1, 1, 0, 1,
1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1,
0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0,
1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 0,
1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0,
0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 1,
1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1,
1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1,
1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0,
1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0,
0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0,
1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1,
0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1,
0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 1,
1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0,
1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1,
1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1,
0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
0, 1, 0, 1, 0, 1, 1, 0, 0, 1, 1, 0,
1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0,
1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0,
1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 0,
1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 0,
1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1,
1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1,
0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0,
0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0,
0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1,
0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1,
0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0,
1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1,
0, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 1,
1, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1,
1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1,
1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0,
1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0,
1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1,
1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0,
1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1,
1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1,
1, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0,
0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1,
1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0,
0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0,
0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0,
1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1,
1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1,
0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1,
0, 0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1,
0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 1,
0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0,
0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1,
0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1,
1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1,
1, 1, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1,
1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 0,
0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1,
0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0,
0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1,
1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 1,
0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1,
0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0,
1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1,
1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 1,
0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1,
1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 0,
1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1,
1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0,
1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
1, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1, 0,
1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1,
1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1,
1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0,
1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0,
1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1,
1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1,
0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 1,
1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1,
0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1,
0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1,
1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1,
1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1,
0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1,
1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0,
0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1,
1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0,
0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 1,
0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0,
1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0,
0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0,
1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 1,
1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0, 0,
1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1,
1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1,
0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0, 1,
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0,
0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0,
0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 0, 1,
1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1,
0, 0, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0,
1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1,
0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1,
1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0,
1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1,
1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1,
1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1,
0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1,
1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0,
1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1,
0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0,
1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0,
1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0,
0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 1,
0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1,
1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1,
0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1,
0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 1, 1,
1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0,
1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
0, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0,
1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0,
1, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0,
1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0,
0, 1, 1, 1, 0, 1, 0, 0, 0, 0, 1, 1,
0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0,
0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1,
0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0,
0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 0,
1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 1, 0,
0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1,
0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 1,
1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1,
0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0,
0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0,
1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1,
0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0,
0, 0, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
1, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0,
0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1,
1, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1,
0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1,
1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0,
1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1,
1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0,
0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0,
1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1,
1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1,
0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1,
1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0,
0, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0,
1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0,
0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0,
0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0,
0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 0, 1,
1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 1, 1,
0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0,
1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0,
0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0,
1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 0,
1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 0,
1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1,
0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0,
0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0,
1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1,
1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0,
0, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0,
1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0,
1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1,
1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1,
0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1,
0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0,
1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1,
1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 1, 0,
0, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 1,
1, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0,
0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1,
0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 0,
1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0,
1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0,
1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0,
0, 0, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0,
0, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0,
1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1,
1, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1,
1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 1,
1, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1,
0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0,
0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0,
0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0,
1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1,
0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1,
1, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 1,
0, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 1,
0, 1, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0,
1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
0, 0, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0,
1, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1,
0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1,
1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0,
0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1,
0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0,
0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0,
1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 1, 0,
0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0,
0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1, 1,
1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0,
1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1,
0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0,
0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1,
0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0,
0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0,
0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1,
0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 0, 1,
0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1,
1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1,
1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1,
0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1, 0,
1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
0, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0,
0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0,
0, 0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 1,
0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0,
0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1,
1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0,
1, 1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0,
0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1,
1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 0,
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 1,
1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0,
1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 0, 1,
0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1,
0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0,
1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0,
1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1,
1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1,
1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1,
1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1,
1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1,
1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 1,
1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0,
1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0,
0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1,
0, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1,
0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0,
1, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0,
1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0,
1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0,
0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,
1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0, 0,
1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
0, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0, 0,
1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 0,
1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1,
0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 1,
1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1,
0, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1,
1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0,
1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 0,
0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0,
1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1, 0,
0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0,
1, 1, 1, 0, 0, 0, 1, 1, 0, 1, 0, 1,
0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1,
0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0,
1, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1,
1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1,
1, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1,
1, 1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 0,
0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1,
0, 0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0,
1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 1,
1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 1, 0,
0, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0,
1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 0,
1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0,
1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0,
0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 0,
1, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1,
1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 0, 0,
0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 1,
0, 0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 0,
1, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 1, 1,
1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
0, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 1,
0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0, 1,
1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1,
0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0,
0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 0,
0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0,
1, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0,
1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1,
1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0,
1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
0, 0, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0,
1, 1, 1, 0, 0, 1, 0, 1, 1, 1, 1, 1,
1, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 1,
0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1,
0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 0,
0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 0,
1, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0,
0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1,
0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0,
0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1,
1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1,
0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 0,
0, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1,
0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1,
0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1,
1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0,
1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1,
0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 0,
0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1,
1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1, 1,
1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1,
0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1,
1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1,
1, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0,
1, 0, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1,
0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0,
1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1,
0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1,
0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 1, 1,
1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 0, 1,
1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1,
0, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 1,
1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0,
1, 0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1,
0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0,
1, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0,
1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0,
1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0,
0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 1,
0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0,
1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0,
0, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0,
1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0,
0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1,
0, 1, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1,
0, 0, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1,
1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0, 0,
1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 0, 1,
0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0,
0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0, 1,
0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0,
0, 0, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1,
0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 1, 0,
0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0,
1, 1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0,
1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1,
1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1,
0, 0, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1,
1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0,
1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 0,
0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0,
1, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0,
1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1,
0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 1,
1, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 1,
1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 1,
0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0,
1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1,
1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0,
0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 0,
1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0,
0, 1, 0, 0, 1, 1, 1, 1, 1, 1, 0, 1,
0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0,
1, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0,
1, 0, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0,
1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 1, 0,
0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1,
1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1,
0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 1, 1,
0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 1,
0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0,
1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1,
1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1,
0, 1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 0,
1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 0, 0,
0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1,
0, 0, 1, 1, 1, 0, 1, 0, 0, 0, 1, 1,
1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0,
0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0,
0, 0, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0,
1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 0,
0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0,
0, 1, 1, 1, 0, 1, 0, 0, 1, 0, 0, 0,
0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0,
0, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 1,
1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0,
0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1,
0, 1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 0,
1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 1,
1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1,
0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 0, 1,
1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0,
0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 0,
1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 1, 0,
1, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0,
0, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 1,
1, 0, 1, 0, 1, 1, 0, 0, 0, 1, 1, 1,
0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 1,
0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0,
0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 0, 0,
1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1,
1, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 0,
0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0,
1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 1,
0, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 0,
0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1,
1, 1, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0,
1, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1,
0, 0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0,
0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0,
0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0,
0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0,
1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0,
1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1,
0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0,
1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0,
1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0,
1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
0, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1,
1, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0,
1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0,
1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1,
0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1, 0,
1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0, 0,
1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0,
0, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 0,
1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 0,
1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 1,
1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0,
1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0,
0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0,
0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0,
0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0,
1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1,
0, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1,
0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0,
0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0,
0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 1,
0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0,
1, 0, 1, 0, 1, 1, 1, 0, 1, 0, 0, 0,
0, 0, 1, 0, 1, 0, 1, 1, 1, 0, 0, 0,
0, 1, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0,
1, 0, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1,
1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0,
0, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 1,
0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1,
0, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 0,
0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0,
1, 1, 0, 1, 0, 0, 1, 1, 0, 1, 1, 0,
0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 1,
0, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1,
0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1,
1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 1,
0, 0, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0,
1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0, 1,
1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0,
1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1,
1, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0,
0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1,
1, 0, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0,
0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1,
0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 1, 1, 1, 1, 1, 0, 0, 1, 0, 1, 0,
0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 1,
0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0,
1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 1,
0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0,
1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1,
1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1,
1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1,
1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1,
1, 0, 1, 1, 1, 0, 0, 1, 0, 1, 1, 1,
1, 1, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1,
0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 1,
0, 1, 0, 0, 1, 1, 1, 0, 1, 1, 0, 0,
1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1, 1,
0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1,
0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1,
1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 0,
1, 1, 0, 1, 1, 0, 1, 0, 1, 0, 1, 0,
1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1,
1, 0, 1, 0, 1, 0, 1, 1, 1, 0, 1, 0,
1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0,
1, 0, 0, 1, 1, 0, 1, 0, 1, 1, 0, 1,
1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1,
1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0,
0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1,
1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1,
0, 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0,
0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1,
0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 1,
0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1,
0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1, 0,
1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0,
1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1,
0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0,
0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1,
1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 1,
0, 1, 1, 1, 0, 1, 1, 0, 1, 1, 1, 0,
1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0,
1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 0, 1,
1, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1,
0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1,
1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0,
0, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0,
1, 1, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1,
0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1,
1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1,
0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0,
1, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1,
1, 0, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1,
1, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 1,
1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0,
0, 0, 0, 1, 0, 1, 1, 0, 0, 1, 1, 1,
0, 1, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0,
0, 1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1,
0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
1, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0,
1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 1,
1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0,
1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0,
0, 0, 1, 1, 0, 0, 1, 0, 1, 1, 0, 0,
1, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 0,
1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 1, 0,
1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0,
1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0,
1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0,
0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1,
1, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0, 1,
0, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0,
1, 0, 1, 0, 1, 0, 0, 1, 0, 1, 0, 1,
0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1,
1, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1,
0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 0,
0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 1, 1,
0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0,
0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0,
1, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1,
1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1,
0, 0, 1, 0, 1, 1, 0, 0, 1, 0, 0, 1,
0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1,
0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 1, 0,
1, 0, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1,
1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 1,
0, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1,
1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1,
1, 0, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0,
1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0,
1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1,
1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 0, 0,
0, 0, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1,
0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1};
