//A robot is located at the top - left corner of a m x n grid(marked 'Start' in the diagram below).
//
//The robot can only move either down or right at any point in time.The robot is trying to reach the bottom - right corner of the grid(marked 'Finish' in the diagram below).
//
//How many possible unique paths are there ?
//
//
//Above is a 7 x 3 grid.How many possible unique paths are there ?
//
//Note : m and n will be at most 100.
//
//	Example 1 :
//
//	Input : m = 3, n = 2
//	Output : 3
//	Explanation :
//	From the top - left corner, there are a total of 3 ways to reach the bottom - right corner :
//1. Right->Right->Down
//2. Right->Down->Right
//3. Down->Right->Right
//
//Example 2 :
//
//	Input : m = 7, n = 3
//	Output : 28
//
//


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths.
//Memory Usage : 8.6 MB, less than 40.09% of C++ online submissions for Unique Paths.

class Solution {
public:
	int uniquePaths(int m, int n) {
		vector<vector<int>> vecAll(m, vector<int>(n, 1));
		for (int row = 1; row < m; ++row) {
			for (int col = 1; col < n; ++col) { vecAll[row][col] = vecAll[row - 1][col] + vecAll[row][col - 1]; }
		}
		return vecAll[m - 1][n - 1];
	}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Unique Paths.
//Memory Usage : 8.3 MB, less than 62.47% of C++ online submissions for Unique Paths.

class Solution {
public:
	long double fac(long double i) {
		if (i == 0) { return 1; }
		else {
			for (int f = i - 1; f > 0; --f) { i *= f; }
			return i;
		}
	}

	int uniquePaths(int m, int n) {
		int iN = m + n - 2;
		int iR;
		if (m < n) { iR = m - 1; }
		else { iR = n - 1; }
		long double iFact = 1;
		for (int i = iN; i > (iN - iR); --i) { iFact *= i; }

		return iFact / fac(iR);
	}
};