//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in - place.
//
//Example 1:
//
//Input:
//[
//	[1, 1, 1],
//	[1, 0, 1],
//	[1, 1, 1]
//]
//Output :
//	[
//		[1, 0, 1],
//		[0, 0, 0],
//		[1, 0, 1]
//	]
//
//	   Example 2:
//
//   Input:
//	   [
//		   [0, 1, 2, 0],
//		   [3, 4, 5, 2],
//		   [1, 3, 1, 5]
//	   ]
//	   Output :
//		   [
//			   [0, 0, 0, 0],
//			   [0, 4, 5, 0],
//			   [0, 3, 1, 0]
//		   ]
//
//			  Follow up :
//
//			  A straight forward solution using O(mn) space is probably a bad idea.
//				  A simple improvement uses O(m + n) space, but still not the best solution.
//				  Could you devise a constant space solution ?
//


//Runtime: 48 ms, faster than 99.42% of C++ online submissions for Set Matrix Zeroes.
//Memory Usage : 11.4 MB, less than 83.76% of C++ online submissions for Set Matrix Zeroes.

class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		if (matrix.size() == 0) { return; }
		vector<int> mRow, mCol;
		for (int row = 0; row < matrix.size();++row) {
			for (int col = 0; col < matrix[0].size();++col) {
				if (matrix[row][col] == 0) {
					if (find(mRow.begin(), mRow.end(), row) == mRow.end()) { mRow.push_back(row); }
					if (find(mCol.begin(), mCol.end(), col) == mCol.end()) { mCol.push_back(col); }
				}
			}
		}
		for (int i = 0; i < mRow.size(); ++i) {
			for (int col = 0; col < matrix[mRow[i]].size(); ++col) { matrix[mRow[i]][col] = 0; }
		}
		for (int i = 0; i < mCol.size(); ++i) {
			for (int row = 0; row < matrix.size(); ++row) { matrix[row][mCol[i]] = 0; }
		}
		return;
	}
};