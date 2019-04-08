#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

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

int main() {





	std::cout << "Wuzup world!" << std::endl;
	return 0;
}