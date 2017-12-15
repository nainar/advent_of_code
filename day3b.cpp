#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
using namespace std;

/*
d 	e 	f
c	a 	b
g 	e 	f
*/

int param = 368078;
const int MAX_ROWS = ceil(sqrt (param));
const int MAX_COLS = ceil(sqrt (param));

int main() 
{

	int matrix[MAX_ROWS][MAX_COLS];
	memset(matrix, 0, MAX_ROWS * MAX_COLS * sizeof(int));
	int levl;
    int c = MAX_COLS/2;
    int x,y;
    x = y = c;
    matrix[c][c] = 1;

    // Printing inwards to outwards. Works only for odd sized 2D array with one element in center
    for(levl=1; c+levl<=MAX_COLS; levl++)
    {
        for(; y<=c+levl && y < MAX_COLS; y++) {
        	int sum = matrix[x][y+1] + matrix[x][y-1] + matrix[x-1][y] + matrix[x+1][y] + matrix[x-1][y-1] + matrix[x-1][y+1] + matrix[x+1][y+1] + matrix[x+1][y-1];
        	if (sum > param) {
        		cout << "Answer: " << sum << endl;
        		return 0;
        	}
        	matrix[x][y] = sum ? sum : 1;
        }

        // Since we always start from the center going towards right, top row (going left to right)
        // will always be the last remaining row to print
        if (x == 0 && y == MAX_COLS) // we are done
            break;

        for(x++,y--; x<=c+levl && x < MAX_COLS; x++)  {
        	int sum = matrix[x][y+1] + matrix[x][y-1] + matrix[x-1][y] + matrix[x+1][y] + matrix[x-1][y-1] + matrix[x-1][y+1] + matrix[x+1][y+1] + matrix[x+1][y-1];
        	if (sum > param) {
        		cout << "Answer: " << sum << endl;
        		return 0;
        	}
        	matrix[x][y] = sum;
        }
        for(x--,y--; y>=c-levl ; y--) {
        	int sum = matrix[x][y+1] + matrix[x][y-1] + matrix[x-1][y] + matrix[x+1][y] + matrix[x-1][y-1] + matrix[x-1][y+1] + matrix[x+1][y+1] + matrix[x+1][y-1];
        	if (sum > param) {
        		cout << "Answer: " << sum << endl;
        		return 0;
        	}
        	matrix[x][y] = sum;
        }
        for(x--,y++; x>=c-levl ;x--) {
        	int sum = matrix[x][y+1] + matrix[x][y-1] + matrix[x-1][y] + matrix[x+1][y] + matrix[x-1][y-1] + matrix[x-1][y+1] + matrix[x+1][y+1] + matrix[x+1][y-1];
        	if (sum > param) {
        		cout << "Answer: " << sum << endl;
        		return 0;
        	}
        	matrix[x][y] = sum;
        }
        x++;
        y++;
    }

    return 0;
}
