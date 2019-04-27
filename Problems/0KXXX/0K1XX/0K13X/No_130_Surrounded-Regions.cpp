//Given a 2D board containing 'X'and 'O' (the letter O), capture all regions surrounded by 'X'.
//
//A region is captured by flipping all 'O's into 'X's in that surrounded region.
//
//Example:
//
//X X X X
//X O O X
//X X O X
//X O X X
//
//After running your function, the board should be :
//
//X X X X
//X X X X
//X X X X
//X O X X
//
//Explanation :
//
//Surrounded regions shouldn’t be on the border, which means that any 'O' on the border of the board are not flipped to 'X'.Any 'O' that is not on the borderand it is not connected to an 'O' on the border will be flipped to 'X'.Two cells are connected if they are adjacent cells connected horizontally or vertically.


//Runtime: 32 ms, faster than 98.95% of C++ online submissions for Surrounded Regions.
//Memory Usage : 14.5 MB, less than 69.23% of C++ online submissions for Surrounded Regions.

class Solution {
public:
	vector<vector<int>>vAll;
	int rowSize, colSize;
	void reS(int r, int c, vector<vector<char>>& board) {
		if (r >= rowSize || c >= colSize || r < 0 || c < 0) { return; }
		if (board[r][c] == 'O' && vAll[r][c] == 0) {
			vAll[r][c] = -1;
			reS(r - 1, c, board);
			reS(r + 1, c, board);
			reS(r, c - 1, board);
			reS(r, c + 1, board);
		}
		return;
	}

	void solve(vector<vector<char>>& board) {
		rowSize = board.size();
		if (rowSize <= 2) { return; }
		colSize = board[0].size();
		if (colSize <= 2) { return; }
		vAll = vector<vector<int>>(rowSize, vector<int>(colSize, 0));
		for (int r = 1; r < rowSize - 1; ++r) {
			for (int c = 0; c < colSize;c += colSize - 1) { reS(r, c, board); }
		}
		for (int r = 0; r < rowSize; r += rowSize - 1) {
			for (int c = 0; c < colSize; ++c) { reS(r, c, board); }
		}
		for (int r = 1; r < rowSize - 1; ++r) {
			for (int c = 1; c < colSize - 1; ++c) { if (board[r][c] == 'O' && vAll[r][c] == 0) { board[r][c] = 'X'; } }
		}
		return;
	}
};