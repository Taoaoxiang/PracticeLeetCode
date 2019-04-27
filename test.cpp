#include "include_LeetCode.h"


//
//class Solution {
//public:
//	int candy(vector<int>& ratings) {
//		int nums = ratings.size();
//		if ( nums == 0) { return 0; }
//		else if (nums == 1) { return 1; }
//		else if (nums == 2) {
//			if (ratings[0] == ratings[1]) { return 2; }
//			else { return 3; }
//		}
//		else {
//			int rtn = 0;
//
//
//
//			sort(ratings.begin(), ratings.end());
//			int iLast = INT_MIN;
//			int iCandy = 0;
//			for (int i = 0; i < nums; ++i) {
//				if (ratings[i] > iLast) {
//					++iCandy;
//					iLast = ratings[i];
//				}
//				else {
//					if (iCandy - 1 > 0) { --iCandy; }
//				}
//				rtn += iCandy;
//			}
//			return rtn;
//		}
//	}
//};

class Solution {
public:
	vector<vector<bool>>vAll;
	int rowSize, colSize;
	void reS(int r, int c, vector<vector<char>>& board) {
		if (r >= rowSize || c >= colSize || r <0 || c <0) { return; }
		if (board[r][c] == 'O' && vAll[r][c] == false) {
			vAll[r][c] = true;
			reS(r-1, c, board);
			reS(r+1, c, board);
			reS(r, c-1, board);
			reS(r, c+1, board);
		}
		return;
	}

	void solve(vector<vector<char>>& board) {
		rowSize = board.size();
		if (rowSize <= 2) { return; }
		colSize = board[0].size();
		if (colSize <= 2) { return; }
		vAll= vector<vector<bool>>(rowSize, vector<bool>(colSize, false));
		for (int r = 1; r < rowSize - 1; ++r) {
			for (int c = 0; c < colSize;c += colSize - 1) { 
				reS(r, c, board); 
			}
		}
		for (int r = 0; r < rowSize ; r += rowSize - 1) {
			for (int c = 0; c < colSize; ++c) { 
				reS(r, c, board); 
			}
		}
		for (int r = 1; r < rowSize - 1; ++r) {
			for (int c = 1; c < colSize - 1; ++c) {
				if (board[r][c] == 'O' && vAll[r][c] == false) { board[r][c] = 'X'; }
			}
		}

		return;
	}
};




int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}