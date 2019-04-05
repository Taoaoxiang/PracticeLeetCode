//Given a m x n grid filled with non - negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.
//
//Note: You can only move either down or right at any point in time.
//
//	Example :
//
//	Input :
//	[
//		[1, 3, 1],
//		[1, 5, 1],
//		[4, 2, 1]
//	]
//Output : 7
//	Explanation : Because the path 1→3→1→1→1 minimizes the sum.
//
//

//Runtime: 12 ms, faster than 98.31% of C++ online submissions for Minimum Path Sum.
//Memory Usage : 10.4 MB, less than 100.00% of C++ online submissions for Minimum Path Sum.

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		for (int row = 0; row < grid.size();++row) {
			for (int col = 0;col < grid[0].size();++col) {
				if (row == 0 && col == 0) { continue; }
				else if (row == 0 && col != 0) { grid[row][col] += grid[row][col - 1]; }
				else if (row != 0 && col == 0) { grid[row][col] += grid[row - 1][col]; }
				else {
					if (grid[row - 1][col] > grid[row][col - 1]) { grid[row][col] += grid[row][col - 1]; }
					else { grid[row][col] += grid[row - 1][col]; }
				}
			}
		}
		return grid[grid.size() - 1][grid[0].size() - 1];
	}
};