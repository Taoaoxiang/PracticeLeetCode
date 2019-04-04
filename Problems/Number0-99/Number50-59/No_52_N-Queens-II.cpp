//The n - queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//Given an integer n, return the number of distinct solutions to the n - queens puzzle.
//
//Example:
//
//Input: 4
//	Output : 2
//	Explanation : There are two distinct solutions to the 4 - queens puzzle as shown below.
//	[
//		[".Q..",  // Solution 1
//		"...Q",
//		"Q...",
//		"..Q."],
//
//		["..Q.",  // Solution 2
//		"Q...",
//		"...Q",
//		".Q.."]
//	]
//


//Runtime: 8 ms, faster than 53.57% of C++ online submissions for N - Queens II.
//Memory Usage : 8.4 MB, less than 50.82% of C++ online submissions for N - Queens II.

class Solution {
public:
	bool isSafe(int row, int col, int nPos, vector<string> &board) {
		for (int i = 0; i <= nPos; ++i) { if (board[row][i] == 'Q') { return false; } }
		for (int i = 0; i <= nPos; ++i) { if (board[i][col] == 'Q') { return false; } }
		for (int i = row, j = col; (i >= 0) && (j >= 0); --i, --j) { if (board[i][j] == 'Q') { return false; } }
		for (int i = row, j = col; (i <= nPos) && (j >= 0); ++i, --j) { if (board[i][j] == 'Q') { return false; } }
		for (int i = row, j = col; (i >= 0) && (j <= nPos); --i, ++j) { if (board[i][j] == 'Q') { return false; } }
		for (int i = row, j = col; (i <= nPos) && (j <= nPos); ++i, ++j) { if (board[i][j] == 'Q') { return false; } }
		return true;
	}

	bool recursiveTry(int row, int col, int nPos, vector<string> &board, int &rtn) {
		if (row > nPos) { return true; }
		for (int i = 0; i <= nPos; ++i) {
			if (isSafe(row, i, nPos, board) == true) {
				board[row][i] = 'Q';
				if (recursiveTry(row + 1, 0, nPos, board, rtn) == true) {
					++rtn;
					board[row][i] = '.';
				}
				else { board[row][i] = '.'; }
			}
		}
		return false;
	}

	int totalNQueens(int n) {
		if (n == 0) { return 1; }
		else if (n == 1) { return 1; }
		else if (n == 2 || n == 3) { return 0; }
		int rtn = 0;
		vector<string> board(n, string(n, '.'));
		int i = 0;
		while (i < n) {
			vector<string> tmpBoard(board);
			tmpBoard[0][i] = 'Q';
			recursiveTry(1, i, n - 1, tmpBoard, rtn);
			++i;
		}

		//cout << "T0:" << rtn.size() << endl;
		//for (int i1 = 0; i1 < rtn.size();++i1) {
		//	cout << "Solution: " << i1 << endl;
		//	for (int i = 0; i < rtn[i1].size();++i) { cout << "Line: " << i << "=> " << rtn[i1][i] << endl; }
		//	cout << endl;
		//}

		return rtn;
	}

};