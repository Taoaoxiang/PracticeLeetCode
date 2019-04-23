//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle.
//Memory Usage : 8.8 MB, less than 54.49% of C++ online submissions for Pascal's Triangle.

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows == 1) { return { {1} }; }
		vector<vector<int>> rtn(numRows, vector<int>());
		vector<vector<int>> vAll(numRows, vector<int>(numRows, 1));
		for (int row = 0; row < numRows; ++row) {
			for (int col = 0; col < (numRows - row); ++col) {
				//cout << "Row=>" << row << ", Col=>" << col << endl;
				if (row != 0 && col != 0) { vAll[row][col] = vAll[row - 1][col] + vAll[row][col - 1]; }
				rtn[row + col].push_back(vAll[row][col]);
			}
		}
		return rtn;
	}
};