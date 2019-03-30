//Write a program to solve a Sudoku puzzle by filling the empty cells.
//
//A sudoku solution must satisfy all of the following rules :
//
//Each of the digits 1 - 9 must occur exactly once in each row.
//Each of the digits 1 - 9 must occur exactly once in each column.
//Each of the the digits 1 - 9 must occur exactly once in each of the 9 3x3 sub - boxes of the grid.
//
//Empty cells are indicated by the character '.'.
//
//
//A sudoku puzzle...
//
//
//...and its solution numbers marked in red.
//
//Note:
//
//The given board contain only digits 1 - 9 and the character '.'.
//You may assume that the given Sudoku puzzle will have a single unique solution.
//The given board size is always 9x9.
//


//Runtime: 16 ms, faster than 62.35% of C++ online submissions for Sudoku Solver.
//Memory Usage : 9.2 MB, less than 29.77% of C++ online submissions for Sudoku Solver.

// This one is kind of hard
// Have to use backtracking at last
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>

using namespace std;

class Solution {
public:
	// Check the number, remove the same number from the vCtrl
	// Find the number and erase 
	void findNErase(int row, int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		if (vCtrl[row][col].size() == 1) { board[row][col] = vCtrl[row][col].back(); }
		else {
			auto it = find(vCtrl[row][col].begin(), vCtrl[row][col].end(), c);
			if (it != vCtrl[row][col].end()) {
				vCtrl[row][col].erase(it);
				if (vCtrl[row][col].size() == 1) {
					board[row][col] = vCtrl[row][col].back();
					//cout << "findNErase: Row=>" << row+1 << ", Col=>" << col+1 << ", #=>" << vCtrl[row][col].back() << endl;
				}
			}
		}
		return;
	}
	void numCheckRow(int row, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		for (int i = 0; i < 9; ++i) {
			if (board[row][i] == '.') { findNErase(row, i, vCtrl, c, board); }
		}
		return;
	}
	void numCheckCol(int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		for (int i = 0; i < 9; ++i) {
			if (board[i][col] == '.') { findNErase(i, col, vCtrl, c, board); }
		}
		return;
	}
	void numCheckSub(int row, int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		for (int iRow = row - (row % 3); iRow < (row - (row % 3) + 3); ++iRow) {
			for (int iCol = col - (col % 3); iCol < (col - (col % 3) + 3); ++iCol) {
				if (board[iRow][iCol] == '.') { findNErase(iRow, iCol, vCtrl, c, board); }
			}
		}
		return;
	}
	// Check the dot, get the potential number
	// Find the number and plus
	int findNPlus(int row, int col, vector<vector<vector<char>>>& vCtrl, char c) {
		auto it = find(vCtrl[row][col].begin(), vCtrl[row][col].end(), c);
		if (it != vCtrl[row][col].end()) { return 1; }
		else { return 0; }
	}
	bool dotCheckRow(int row, int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		int iFound = 0;
		for (int i = 0; i < 9; ++i) {
			if (i != col) { iFound += findNPlus(row, i, vCtrl, c); }
		}
		if (iFound == 0) {
			vCtrl[row][col].clear();
			vCtrl[row][col].push_back(c);
			board[row][col] = c;
			//cout << "dotCheckRow: Row=>" << row + 1 << ", Col=>" << col + 1 << ", #=>" << c << endl;
			return true;
		}
		else { return false; }
	}
	bool dotCheckCol(int row, int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		int iFound = 0;
		for (int i = 0; i < 9; ++i) {
			if (i != row) { iFound += findNPlus(i, col, vCtrl, c); }
		}
		if (iFound == 0) {
			vCtrl[row][col].clear();
			vCtrl[row][col].push_back(c);
			board[row][col] = c;
			//cout << "dotCheckCol: Row=>" << row + 1 << ", Col=>" << col + 1 << ", #=>" << c << endl;
			return true;
		}
		else { return false; }
	}
	bool dotCheckSub(int row, int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		int iFound = 0;
		for (int iRow = row - (row % 3); iRow < (row - (row % 3) + 3); ++iRow) {
			for (int iCol = col - (col % 3); iCol < (col - (col % 3) + 3); ++iCol) {
				if ((iRow != row || iCol != col)) { iFound += findNPlus(iRow, iCol, vCtrl, c); }
			}
		}
		if (iFound == 0) {
			vCtrl[row][col].clear();
			vCtrl[row][col].push_back(c);
			board[row][col] = c;
			//cout << "dotCheckSub: Row=>" << row + 1 << ", Col=>" << col + 1 << ", #=>" << c << endl;
			return true;
		}
		else { return false; }
	}

	void numCheckCombo(int row, int col, vector<vector<vector<char>>>& vCtrl, char c, vector<vector<char>>&board) {
		numCheckRow(row, vCtrl, c, board);
		numCheckCol(col, vCtrl, c, board);
		numCheckSub(row, col, vCtrl, c, board);
	}

	bool checkCell(int row, int col, char c, vector<vector<char>>&board) {
		for (int i = 0; i < 9;++i) { if (board[row][i] == c) { return false; } }
		for (int i = 0; i < 9;++i) { if (board[i][col] == c) { return false; } }
		for (int iRow = row - (row % 3); iRow < (row - (row % 3) + 3); ++iRow) {
			for (int iCol = col - (col % 3); iCol < (col - (col % 3) + 3); ++iCol) {
				if (board[iRow][iCol] == c) { return false; }
			}
		}
		return true;
	}

	bool recursiveTry(int row, int col, vector<vector<vector<char>>>& vCtrl, vector<vector<char>>&board) {
		if (col > 8) {
			col = 0;
			row += 1;
			if (row > 8) { return true; }
		}
		if (board[row][col] == '.') {
			for (int i = 0; i < vCtrl[row][col].size();++i) {
				if (checkCell(row, col, vCtrl[row][col][i], board) == true) {
					board[row][col] = vCtrl[row][col][i];
					if (recursiveTry(row, col + 1, vCtrl, board) == true) { return true; }
					else { board[row][col] = '.'; }
				}
			}
		}
		else { return recursiveTry(row, col + 1, vCtrl, board); }
		return false;
	}

	void solveSudoku(vector<vector<char>>& board) {
		// Initialize the vCtrl 
		vector<char> vCandidates = { '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		vector<vector<vector<char>>> vCtrl(9, vector<vector<char>>(9, vCandidates));
		for (int iRow = 0; iRow < 9; ++iRow) {
			for (int iCol = 0; iCol < 9;++iCol) {
				if (board[iRow][iCol] != '.') {
					vCtrl[iRow][iCol].clear();
					vCtrl[iRow][iCol].push_back(board[iRow][iCol]);
					numCheckCombo(iRow, iCol, vCtrl, board[iRow][iCol], board);
				}
			}
		}
		// Start to check
		// This works for normal case;
		vector<int> vecCtrl, vecCtrlTemp, vecCtrlFinish(81, 1);
		while (true) {
			vecCtrlTemp.clear();
			for (int iRow = 0; iRow < 9; ++iRow) {
				for (int iCol = 0; iCol < 9;++iCol) {
					if (board[iRow][iCol] != '.') { numCheckCombo(iRow, iCol, vCtrl, board[iRow][iCol], board); }
					else {
						for (int i = 0; i < vCtrl[iRow][iCol].size(); ++i) {
							if (dotCheckRow(iRow, iCol, vCtrl, vCtrl[iRow][iCol][i], board) == true) {
								numCheckCombo(iRow, iCol, vCtrl, board[iRow][iCol], board);
								break;
							}
							if (dotCheckCol(iRow, iCol, vCtrl, vCtrl[iRow][iCol][i], board) == true) {
								numCheckCombo(iRow, iCol, vCtrl, board[iRow][iCol], board);
								break;
							}
							if (dotCheckSub(iRow, iCol, vCtrl, vCtrl[iRow][iCol][i], board) == true) {
								numCheckCombo(iRow, iCol, vCtrl, board[iRow][iCol], board);
								break;
							}
						}
					}
					vecCtrlTemp.push_back(vCtrl[iRow][iCol].size());
				}
			}
			if (vecCtrlTemp == vecCtrlFinish) { return; }
			else {
				if (vecCtrlTemp != vecCtrl) { vecCtrl = vecCtrlTemp; }
				else { break; }
			}
			//cout << "Ctrl: " << endl;
		}

		// Do backtracking
		recursiveTry(0, 0, vCtrl, board);

		//// Check Control;
		//int bb = 0;
		//for (int iRow = 0; iRow < 9; ++iRow) {
		//	cout << "Line " << ++bb << ": ";
		//	for (int iCol = 0; iCol < 9;++iCol) { cout << board[iRow][iCol] << ", "; }
		//	cout << endl;
		//}
		//bb = 0;
		//for (int iRow = 0; iRow < 9; ++iRow) {
		//	for (int iCol = 0;iCol < 9;++iCol) {
		//		if (vCtrl[iRow][iCol].size() > 1){
		//			cout << "#" << ++bb <<", Row=>" << iRow + 1 << ", Col=>" << iCol + 1 <<" :";
		//			for (int i = 0; i < vCtrl[iRow][iCol].size();++i) {
		//				cout << vCtrl[iRow][iCol][i] << ", ";
		//			}
		//			cout << endl;
		//		}
		//	}
		//}

	}
};


int main() {

	vector<vector<char>> boards = {
		{ '5', '3', '.', '.', '7', '.', '.', '.', '.' },
		{ '6', '.', '.', '1', '9', '5', '.', '.', '.' },
		{ '.', '9', '8', '.', '.', '.', '.', '6', '.' },
		{ '8', '.', '.', '.', '6', '.', '.', '.', '3' },
		{ '4', '.', '.', '8', '.', '3', '.', '.', '1' },
		{ '7', '.', '.', '.', '2', '.', '.', '.', '6' },
		{ '.', '6', '.', '.', '.', '.', '2', '8', '.' },
		{ '.', '.', '.', '4', '1', '9', '.', '.', '5' },
		{ '.', '.', '.', '.', '8', '.', '.', '7', '9' },
	};

	boards = {
	{'.', '.', '9', '7', '4', '8', '.', '.', '.'},
	{'7', '.', '.', '.', '.', '.', '.', '.', '.'},
	{'.', '2', '.', '1', '.', '9', '.', '.', '.'},
	{'.', '.', '7', '.', '.', '.', '2', '4', '.'},
	{'.', '6', '4', '.', '1', '.', '5', '9', '.'},
	{'.', '9', '8', '.', '.', '.', '3', '.', '.'},
	{'.', '.', '.', '8', '.', '3', '.', '2', '.'},
	{'.', '.', '.', '.', '.', '.', '.', '.', '6'},
	{'.', '.', '.', '2', '7', '5', '9', '.', '.'},
	};
	Solution().solveSudoku(boards);

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}