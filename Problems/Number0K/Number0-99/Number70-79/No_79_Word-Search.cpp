//Given a 2D board and a word, find if the word exists in the grid.
//
//The word can be constructed from letters of sequentially adjacent cell, where "adjacent" cells are those horizontally or vertically neighboring.The same letter cell may not be used more than once.
//
//Example:
//
//board =
//[
//	['A', 'B', 'C', 'E'],
//	['S', 'F', 'C', 'S'],
//	['A', 'D', 'E', 'E']
//]
//
//Given word = "ABCCED", return true.
//Given word = "SEE", return true.
//Given word = "ABCB", return false.
//


//Runtime: 24 ms, faster than 97.29% of C++ online submissions for Word Search.
//Memory Usage : 10.6 MB, less than 82.58% of C++ online submissions for Word Search.

class Solution {
public:
	int iRow;
	int iCol;

	bool reSearch(int row, int col, int pos, vector<vector<char>>& board, string& word, vector<vector<int>> &boardTrack) {
		if (pos >= word.size()) { return true; }
		if ((row >= iRow || row < 0) || (col >= iCol || col < 0)) { return false; }
		else {
			if (boardTrack[row][col] != 0 || board[row][col] != word[pos]) { return false; }
			boardTrack[row][col] = 1;
			if (reSearch(row, col - 1, pos + 1, board, word, boardTrack)
				|| reSearch(row, col + 1, pos + 1, board, word, boardTrack)
				|| reSearch(row - 1, col, pos + 1, board, word, boardTrack)
				|| reSearch(row + 1, col, pos + 1, board, word, boardTrack) == true)
			{
				return true;
			}
			else {
				boardTrack[row][col] = 0;
				return false;
			}
		}
	}

	bool exist(vector<vector<char>>& board, string word) {
		if (word.size() == 0) { return true; }
		iRow = board.size();
		iCol = board[0].size();
		vector<vector<int>> boardTrack(iRow, vector<int>(iCol, 0));
		for (int i = 0; i < iRow; ++i) {
			vector<char>::iterator it = find(board[i].begin(), board[i].end(), word[0]);
			while (it != board[i].end()) {
				if (reSearch(i, it - board[i].begin(), 0, board, word, boardTrack) == true) { return true; }
				it = find(it + 1, board[i].end(), word[0]);
			}
		}
		return false;
	}
};