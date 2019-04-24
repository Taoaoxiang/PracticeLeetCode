//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//Now consider if some obstacles are added to the grids.How many unique paths would there be ?
//
//An obstacle and empty space is marked as 1 and 0 respectively in the grid.
//
//Note : m and n will be at most 100.
//
//	Example 1 :
//
//	Input :
//	[
//		[0, 0, 0],
//		[0, 1, 0],
//		[0, 0, 0]
//	]
//Output : 2
//	Explanation :
//	There is one obstacle in the middle of the 3x3 grid above.
//	There are two ways to reach the bottom - right corner :
//		 1. Right->Right->Down->Down
//			 2. Down->Down->Right->Right
//


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths II.
//Memory Usage : 9.4 MB, less than 8.82% of C++ online submissions for Unique Paths II.

// I think 1*1 should be excluded from the testcases.
class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		vector<vector<double>> vecAll(obstacleGrid.size(), vector<double>(obstacleGrid[0].size(), 1));
		for (int row = 0; row < obstacleGrid.size(); ++row) {
			for (int col = 0; col < obstacleGrid[0].size();++col) {
				if (row == 0 && col == 0) {
					if (obstacleGrid[row][col] == 1) { vecAll[row][col] = 0; }
					else { vecAll[row][col] = 1; }
				}
				else if (row == 0 && col != 0) {
					if (obstacleGrid[row][col] == 1) { vecAll[row][col] = 0; }
					else { vecAll[row][col] = vecAll[row][col - 1]; }
				}
				else if (row != 0 && col == 0) {
					if (obstacleGrid[row][col] == 1) { vecAll[row][col] = 0; }
					else { vecAll[row][col] = vecAll[row - 1][col]; }
				}
				else {
					if (obstacleGrid[row][col] == 1) { vecAll[row][col] = 0; }
					else { vecAll[row][col] = vecAll[row - 1][col] + vecAll[row][col - 1]; }
				}
			}
		}
		return vecAll[vecAll.size() - 1][vecAll[0].size() - 1];
	}
};