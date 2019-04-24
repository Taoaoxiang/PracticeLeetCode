//Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
//
//Note that the row index starts from 0.
//
//
//In Pascal's triangle, each number is the sum of the two numbers directly above it.
//
//Example:
//
//Input: 3
//Output: [1,3,3,1]
//
//Follow up:
//
//Could you optimize your algorithm to use only O(k) extra space?


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Pascal's Triangle II.
//Memory Usage : 8.4 MB, less than 81.52% of C++ online submissions for Pascal's Triangle II.

// I think this solution uses extra O(k) space :)
class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> rtn = { 1 };
		if (rowIndex == 0) { return rtn; }
		for (int i = 1; i <= rowIndex; ++i) {
			rtn.insert(rtn.begin(), 0);
			for (int pos = 0; pos < rtn.size() - 1; ++pos) {
				rtn[pos] += rtn[pos + 1];
			}
		}
		return rtn;
	}
};

//Runtime: 8 ms, faster than 16.16% of C++ online submissions for Pascal's Triangle II.
//Memory Usage : 8.9 MB, less than 8.53% of C++ online submissions for Pascal's Triangle II.

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		if (rowIndex == 0) { return { 1 }; }
		else if (rowIndex == 1) { return { 1, 1 }; }
		vector<vector<int>> rtn(rowIndex + 1, vector<int>());
		vector<vector<int>> vAll(rowIndex + 1, vector<int>(rowIndex + 1, 1));
		for (int row = 0; row <= rowIndex; ++row) {
			for (int col = 0; col <= (rowIndex - row); ++col) {
				//cout << "Row=>" << row << ", Col=>" << col << endl;
				if (row != 0 && col != 0) { vAll[row][col] = vAll[row - 1][col] + vAll[row][col - 1]; }
				rtn[row + col].push_back(vAll[row][col]);
			}
		}
		return rtn[rowIndex];
	}
};