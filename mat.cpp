#include <iostream>
#include <vector>
using namespace std;

#include "mat.hpp"

namespace ariel {
    static const int min_char = 33; // the lowest char that can be inputted
    static const int max_char = 126; // the highest char that can be inputted

	string mat(int col, int row, char symb1, char symb2) {
		if(col < 0 || col%2 != 1 || row < 0 || row%2 != 1 || symb1 < min_char || symb1 > max_char || symb2 < min_char || symb2 > max_char) {
            throw invalid_argument("Mat size is always odd!");
        }

        // initiallize the vector and fill with symb1
        vector<vector<char>> vect(row, vector<char>(col, symb1));
		
		// paint every other square with symb2
        for(int k = 1; k <= col/2 && k <= row/2; k += 2) {
            // draw top and bottom line with symb2
            for(int i = k; i < col - k; i++) {
                vect[k][i] = symb2;
                vect[row-k-1][i] = symb2;
            }
            // draw left and right side with symb2
            for(int i = k; i < row - k; i++) {
                vect[i][k] = symb2;
                vect[i][col-k-1] = symb2;
            }
        }
        
        string ans; // will hold the string to be returned
        
        // create a string from the vector
        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                ans += vect[i][j];
            }
            ans += "\n";
        }
        
        return ans;
	}
}
