#include <iostream>
#include <stdio.h>      /* printf */
#include <math.h>       /* sqrt */
using namespace std;

int main() 
{
	int param = 368078;
  	const int squareroot = ceil(sqrt (param));
  	int matrix[squareroot][squareroot];
  	int value = squareroot*squareroot;
  	int xpos, ypos, one_x_pos, one_y_pos;

  	int top = 0, bottom = squareroot - 1;
	int left = 0, right = squareroot - 1;

	int index = 0;

	while (1) 
	{
		if (left > right)
			break;
		// print bottom row
		for (int i = right; i >= left; i--) {
			matrix[bottom][i] = value--;
		}
		bottom--;

		if (top > bottom)
			break;
		// print left column
		for (int i = bottom; i >= top; i--) {
			matrix[i][left] = value--;
		}
		left++;

		if (left > right)
			break;
		// print top row
		for (int i = left; i <= right; i++) {
			matrix[top][i] = value--;
		}
		top++;

		if (top > bottom)
			break;
		// print right column
		for (int i = top; i <= bottom; i++) {
			matrix[i][right] = value--;
		}
		right--;

	}

  	for (int i=0; i < squareroot; i++) {
  		for (int j=0; j < squareroot; j++) {
			// cout << matrix[i][j] << "	";
			if (matrix[i][j] == param) {
  				xpos = i;
  				ypos = j;
  			}
  			else if(matrix[i][j] == 1) {
  				one_x_pos = i;
  				one_y_pos = j;
  			}
  		}
  		// cout << endl;
  	}

	cout << "param at " << xpos << " " << ypos << endl;
	cout << "one at " << one_x_pos << " " << one_y_pos << endl;

  	cout << "Answer: " << abs(xpos-one_x_pos)+abs(ypos-one_y_pos) << endl;

    return 0;
}
