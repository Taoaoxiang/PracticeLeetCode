//Given a matrix of m x n elements(m rows, n columns), return all elements of the matrix in spiral order.
//
//Example 1:
//
//Input:
//[
//	[1, 2, 3],
//	[4, 5, 6],
//	[7, 8, 9]
//]
//Output : [1, 2, 3, 6, 9, 8, 7, 4, 5]
//
//	Example 2 :
//
//	Input :
//	[
//		[1, 2, 3, 4],
//		[5, 6, 7, 8],
//		[9, 10, 11, 12]
//	]
//		 Output : [1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7]


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Spiral Matrix.
//Memory Usage : 8.7 MB, less than 75.66% of C++ online submissions for Spiral Matrix.

// Well, it takes a while to debug, LOL (Me too weak).
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
	void nextDirection(int& rMin, int& rPos, int& rMax, int& cMin, int& cPos, int& cMax, char &direction) {
		switch (direction)
		{
		case 'L':
			if (cPos == cMin) {
				direction = 'U';
				--rMax;
				--rPos;
			}
			else { --cPos; }
			break;
		case 'R':
			if (cPos == cMax) {
				direction = 'D';
				++rMin;
				++rPos;
			}
			else { ++cPos; }
			break;
		case 'D':
			if (rPos == rMax) {
				direction = 'L';
				--cMax;
				--cPos;
			}
			else { ++rPos; }
			break;
		case 'U':
			if (rPos == rMin) {
				direction = 'R';
				++cMin;
				++cPos;
			}
			else { --rPos; }
			break;
		default:
			break;
		}
	}

	void recursiveSpiral(int rMin, int rPos, int rMax, int cMin, int cPos, int cMax, char direction, vector<vector<int>>& matrix, vector<int> &rtn) {
		if ((rMin > rMax) || (cMin > cMax)) { return; }
		//cout << "Row=>(" << rMin << ", " << rPos << ", " << rMax << "), "
		//	<< "Col=> (" << cMin << ", "<< cPos << "," << cMax << "), " 
		//	<< "Dir=> (" << direction <<"), "
		//	<< "Num=> " << matrix[rPos][cPos] <<endl;
		rtn.push_back(matrix[rPos][cPos]);
		nextDirection(rMin, rPos, rMax, cMin, cPos, cMax, direction);
		return recursiveSpiral(rMin, rPos, rMax, cMin, cPos, cMax, direction, matrix, rtn);
	}

	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) { return {}; }
		else if (matrix.size() == 1) { return matrix.back(); }
		vector<int> rtn;
		recursiveSpiral(0, 0, matrix.size() - 1, 0, 0, matrix[0].size() - 1, 'R', matrix, rtn);

		return rtn;
	}
};


int main() {

	vector<vector<int>> matrix = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
	matrix = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };
	Solution().spiralOrder(matrix);


	std::cout << "Wuzup world!" << std::endl;
	return 0;
}