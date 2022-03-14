#include <iostream>
#include <vector>
using namespace std;

#include "mat.hpp"

namespace ariel {
    static const int minimum = 33;
    static const int maximum = 126;

	string mat(int col, int row, char symb1, char symb2) {
		if(col < 0 || col%2 != 1 || row < 0 || row%2 != 1 || symb1 < minimum || symb1 > maximum || symb2 < minimum || symb2 > maximum) {
            throw invalid_argument("Mat size is always odd!");
        }

        vector<vector<char>> vect(row, vector<char>(col, symb1));
		
		// paint every other ring with symb2
        for(int k = 1; k <= col/2 && k <= row/2; k += 2) {
            // top and bottom line
            for(int i = k; i < col - k; i++) {
                vect[k][i] = symb2;
                vect[row-k-1][i] = symb2;
            }
            // left and right side
            for(int i = k; i < row - k; i++) {
                vect[i][k] = symb2;
                vect[i][col-k-1] = symb2;
            }
        }
        
        string ans;
        
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