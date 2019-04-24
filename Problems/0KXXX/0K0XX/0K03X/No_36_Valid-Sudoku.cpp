//Determine if a 9x9 Sudoku board is valid.Only the filled cells need to be validated according to the following rules :
//
//Each row must contain the digits 1 - 9 without repetition.
//Each column must contain the digits 1 - 9 without repetition.
//Each of the 9 3x3 sub - boxes of the grid must contain the digits 1 - 9 without repetition.
//
//
//A partially filled sudoku which is valid.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//
//Example 1:
//
//Input:
//[
//	["5", "3", ".", ".", "7", ".", ".", ".", "."],
//	["6", ".", ".", "1", "9", "5", ".", ".", "."],
//	[".", "9", "8", ".", ".", ".", ".", "6", "."],
//	["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//	["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//	["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//	[".", "6", ".", ".", ".", ".", "2", "8", "."],
//	[".", ".", ".", "4", "1", "9", ".", ".", "5"],
//	[".", ".", ".", ".", "8", ".", ".", "7", "9"]
//]
//Output: true
//
//	Example 2 :
//
//	Input :
//	[
//		["8", "3", ".", ".", "7", ".", ".", ".", "."],
//		["6", ".", ".", "1", "9", "5", ".", ".", "."],
//		[".", "9", "8", ".", ".", ".", ".", "6", "."],
//		["8", ".", ".", ".", "6", ".", ".", ".", "3"],
//		["4", ".", ".", "8", ".", "3", ".", ".", "1"],
//		["7", ".", ".", ".", "2", ".", ".", ".", "6"],
//		[".", "6", ".", ".", ".", ".", "2", "8", "."],
//		[".", ".", ".", "4", "1", "9", ".", ".", "5"],
//		[".", ".", ".", ".", "8", ".", ".", "7", "9"]
//	]
//		Output: false
//			Explanation : Same as Example 1, except with the 5 in the top left corner being
//			modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
//
//			Note :
//
//			A Sudoku board(partially filled) could be valid but is not necessarily solvable.
//			Only the filled cells need to be validated according to the mentioned rules.
//			The given board contain only digits 1 - 9 and the character '.'.
//			The given board size is always 9x9.
//
//
//
//Runtime: 16 ms, faster than 98.21% of C++ online submissions for Valid Sudoku.
//Memory Usage : 9.4 MB, less than 99.41% of C++ online submissions for Valid Sudoku.

class Solution {
public:
	bool checkRow(int row, int col, vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			if (board[row][i] == board[row][col] && i != col) { return false; }
		}
		return true;
	}

	bool checkCol(int row, int col, vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			if (board[i][col] == board[row][col] && i != row) { return false; }
		}
		return true;
	}

	bool checkSub(int row, int col, vector<vector<char>>& board) {
		for (int iRow = row - (row % 3); iRow < (row - (row % 3) + 3); ++iRow) {
			for (int iCol = col - (col % 3); iCol < (col - (col % 3) + 3); ++iCol) {
				if (board[iRow][iCol] == board[row][col] && (iRow != row || iCol != col)) { return false; }
			}
		}
		return true;
	}

	bool isValidSudoku(vector<vector<char>>& board) {
		for (int iRow = 0; iRow < 9; ++iRow) {
			for (int iCol = 0; iCol < 9;++iCol) {
				if (board[iRow][iCol] != '.') {
					if ((checkRow(iRow, iCol, board) && checkCol(iRow, iCol, board) && checkSub(iRow, iCol, board)) == true) {
						continue;
					}
					else { return false; }
				}
			}
		}
		return true;
	}
};
