//Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
//
//Example:
//
//Input: 3
//	Output :
//	[
//		[1, 2, 3],
//		[8, 9, 4],
//		[7, 6, 5]
//	]
//


//Runtime: 12 ms, faster than 6.39% of C++ online submissions for Spiral Matrix II.
//Memory Usage : 9.2 MB, less than 10.29% of C++ online submissions for Spiral Matrix II.

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

	void recursiveSpiral(int rMin, int rPos, int rMax, int cMin, int cPos, int cMax, char direction, int num, vector<vector<int>>& matrix) {
		if ((rMin > rMax) || (cMin > cMax)) { return; }
		//cout << "Row=>(" << rMin << ", " << rPos << ", " << rMax << "), "
		//	<< "Col=> (" << cMin << ", "<< cPos << "," << cMax << "), " 
		//	<< "Dir=> (" << direction <<"), "
		//	<< "Num=> " << matrix[rPos][cPos] <<endl;
		matrix[rPos][cPos] = num;
		nextDirection(rMin, rPos, rMax, cMin, cPos, cMax, direction);
		return recursiveSpiral(rMin, rPos, rMax, cMin, cPos, cMax, direction, num + 1, matrix);
	}

	vector<vector<int>> generateMatrix(int n) {
		if (n == 1) { return { {1} }; }
		vector<vector<int>> rtn(n, vector<int>(n, 0));
		recursiveSpiral(0, 0, n - 1, 0, 0, n - 1, 'R', 1, rtn);

		return rtn;
	}
};