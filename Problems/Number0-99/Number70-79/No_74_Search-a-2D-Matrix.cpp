//Write an efficient algorithm that searches for a value in an m x n matrix.This matrix has the following properties :
//
//Integers in each row are sorted from left to right.
//The first integer of each row is greater than the last integer of the previous row.
//
//Example 1 :
//
//	Input :
//	matrix = [
//		[1, 3, 5, 7],
//			[10, 11, 16, 20],
//			[23, 30, 34, 50]
//	]
//	target = 3
//		Output: true
//
//		Example 2 :
//
//		Input :
//		matrix = [
//			[1, 3, 5, 7],
//				[10, 11, 16, 20],
//				[23, 30, 34, 50]
//		]
//		target = 13
//			Output: false
//


//Runtime: 12 ms, faster than 98.50% of C++ online submissions for Search a 2D Matrix.
//Memory Usage : 9.8 MB, less than 100.00% of C++ online submissions for Search a 2D Matrix.

class Solution {
public:
	int reSearch(int iStart, int iEnd, vector<int>& mRow, int target) {
		if (mRow[iStart] > target) { return 0; }
		else if (mRow[iEnd] < target) { return 2; }
		int iMid = (iStart + iEnd) / 2;
		while (mRow[iMid] != target) {
			if (iStart == iEnd) { return 0; }
			if (target < mRow[iMid]) {
				iEnd = iMid;
				iMid = (iStart + iEnd) / 2;
			}
			else if (target > mRow[iMid]) {
				iStart = ++iMid;
				iMid = (iStart + iEnd) / 2;
			}
		}
		return 1;
	}

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0) { return false; }
		else if (matrix[0].size() == 0) { return false; }
		for (int row = 0; row < matrix.size(); ++row) {
			int result = reSearch(0, matrix[row].size() - 1, matrix[row], target);
			if (result == 0) { return false; }
			else if (result == 1) { return true; }
			else { continue; }
		}
		return false;
	}
};