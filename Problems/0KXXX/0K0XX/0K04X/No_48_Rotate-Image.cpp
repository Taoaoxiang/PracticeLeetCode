//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Rotate Image.
//Memory Usage : 8.9 MB, less than 100.00% of C++ online submissions for Rotate Image.

// This performance, WOW! RockNRoll
class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		if (matrix.size() <= 1) { return; }
		for (int iRow = 0; iRow < matrix.size() / 2; ++iRow) {
			for (int iCol = iRow; iCol < matrix.size() - 1 - iRow; ++iCol) {
				int thisRow = iRow, thisCol = iCol;
				int iHold = matrix[iRow][iCol];
				//cout << "Row: " << iRow << ", Col: " << iCol << endl;
				while (true) {
					int nRow = thisCol;
					int nCol = matrix.size() - 1 - thisRow;
					int iHoldTemp = matrix[nRow][nCol];
					matrix[nRow][nCol] = iHold;
					iHold = iHoldTemp;
					thisRow = nRow;
					thisCol = nCol;
					if ((thisRow == iRow) && (thisCol == iCol)) { break; }
				}
			}
		}
		return;
	}
};