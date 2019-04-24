//Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
//Example 1:
//
//Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
//	Output : true
//
//	Example 2 :
//
//	Input : s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
//	Output : false
//
//

//Runtime: 8 ms, faster than 53.31% of C++ online submissions for Interleaving String.
//Memory Usage : 8.7 MB, less than 50.00% of C++ online submissions for Interleaving String.

// DP solution
class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) { return false; }
		if (s3.size() == 0) { return true; }
		vector<vector<bool>> vecMatch(s1.size() + 1, vector<bool>(s2.size() + 1, true));
		for (int row = 0; row < s1.size() + 1; row++) {
			for (int col = 0; col < s2.size() + 1; col++) {
				if (row == 0 && col == 0) { continue; }
				else if (row == 0 && col != 0) {
					if (s3[col - 1] != s2[col - 1]) { vecMatch[row][col] = false; }
					else { vecMatch[row][col] = vecMatch[row][col - 1]; }
				}
				else if (row != 0 && col == 0) {
					if (s3[row - 1] != s1[row - 1]) { vecMatch[row][col] = false; }
					else { vecMatch[row][col] = vecMatch[row - 1][col]; }
				}
				else {
					if ((s3[row + col - 1] == s1[row - 1]) && (s3[row + col - 1] == s2[col - 1])) {
						vecMatch[row][col] = vecMatch[row][col - 1] || vecMatch[row - 1][col];
					}
					else if ((s3[row + col - 1] == s1[row - 1]) && (s3[row + col - 1] != s2[col - 1])) {
						vecMatch[row][col] = vecMatch[row - 1][col];
					}
					else if ((s3[row + col - 1] != s1[row - 1]) && (s3[row + col - 1] == s2[col - 1])) {
						vecMatch[row][col] = vecMatch[row][col - 1];
					}
					else { vecMatch[row][col] = false; }
				}
			}
		}

		return vecMatch[s1.size()][s2.size()];
	}
};

//Runtime: 1868 ms, faster than 5.45% of C++ online submissions for Interleaving String.
//Memory Usage : 8.1 MB, less than 97.47% of C++ online submissions for Interleaving String.

// This needs to be improved
class Solution {
public:
	bool reSea(string& s1, int pos1, string& s2, int pos2, string& s3, int pos3) {
		if (pos3 >= s3.size()) { return true; }
		if (s1[pos1] == s2[pos2]) {
			if (s3[pos3] == s1[pos1]) { return reSea(s1, pos1 + 1, s2, pos2, s3, pos3 + 1) || reSea(s1, pos1, s2, pos2 + 1, s3, pos3 + 1); }
			else { return false; }
		}
		else {
			if (s3[pos3] == s1[pos1]) { return reSea(s1, pos1 + 1, s2, pos2, s3, pos3 + 1); }
			else if (s3[pos3] == s2[pos2]) { return reSea(s1, pos1, s2, pos2 + 1, s3, pos3 + 1); }
			else { return false; }
		}

	}
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) { return false; }
		if (s3.size() == 0) { return true; }
		return reSea(s1, 0, s2, 0, s3, 0);
	}
};