//Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
//Example:
//
//Input:
//[
//	["1", "0", "1", "0", "0"],
//	["1", "0", "1", "1", "1"],
//	["1", "1", "1", "1", "1"],
//	["1", "0", "0", "1", "0"]
//]
//Output: 6
//
//

//Runtime: 32 ms, faster than 33.13% of C++ online submissions for Maximal Rectangle.
//Memory Usage : 10.5 MB, less than 100.00% of C++ online submissions for Maximal Rectangle.

class Solution {
public:
	// rowSeek to find the column position of next 0 in the same row
	int rowSeek(int col, vector<char>& matrixRow) {
		return (find(matrixRow.begin() + col + 1, matrixRow.end(), '0') - matrixRow.begin());
	}
	// colSeek to get the row position of next 0 in the same column
	int colSeek(int row, int rowSize, int col, vector<vector<char>>& matrix) {
		for (int i = row + 1; i < rowSize; ++i) { if (matrix[i][col] == '0') { return i; } }
		return rowSize;
	}

	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.size() == 0) { return 0; }
		int rowSize = matrix.size(), colSize = matrix[0].size();
		int maxArea = 0;
		for (int row = 0; row < rowSize; ++row) {
			for (int col = 0; col < colSize;++col) {
				if (matrix[row][col] == '1') {
					//cout << "row=>" << row << ", col=>" << col << endl;
					int area = 0;
					if (row < rowSize - 1 && col < colSize - 1) {
						int colZero = rowSeek(col, matrix[row]);
						int rowZero = colSeek(row, rowSize, col, matrix);
						//cout << "rowZero=>" << rowZero << ", colZero=>" << colZero << endl;
						int rowArea = rowZero - row;
						int colArea = colZero - col;
						area = rowArea > colArea ? rowArea : colArea;
						if (rowArea != 1 && colArea != 1) {
							for (int iCol = col + 1; iCol < colZero; ++iCol) {
								//cout << "iCol=>" << iCol << endl;
								if (rowZero - row == 1) { break; }
								for (int iRow = row + 1; iRow < rowZero; ++iRow) {
									if (matrix[iRow][iCol] == '0') { rowZero = iRow; }
								}
								int recArea = (iCol - col + 1)*(rowZero - row);
								area = recArea > area ? recArea : area;
							}
						}
						else if (rowArea == 1 && colArea != 1) { area = colArea; }
						else if (rowArea != 1 && colArea == 1) { area = rowArea; }
						else { area = 1; }
					}
					else {
						if (row == rowSize - 1 && col == colSize - 1) { area = 1; }
						else if (row == rowSize - 1 && col != colSize - 1) { area = rowSeek(col, matrix[row]) - col; }
						else if (row != rowSize - 1 && col == colSize - 1) { area = colSeek(row, rowSize, col, matrix) - row; }
					}
					//cout << "Area: " << area << endl;
					maxArea = area > maxArea ? area : maxArea;
				}
				else { continue; }
			}
		}
		return maxArea;
	}
};