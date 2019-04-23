//Given a string S and a string T, count the number of distinct subsequences of S which equals T.
//
//A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
//
//Example 1:
//
//Input: S = "rabbbit", T = "rabbit"
//Output: 3
//Explanation:
//
//As shown below, there are 3 ways you can generate "rabbit" from S.
//(The caret symbol ^ means the chosen letters)
//
//rabbbit
//^^^^ ^^
//rabbbit
//^^ ^^^^
//rabbbit
//^^^ ^^^
//
//Example 2:
//
//Input: S = "babgbag", T = "bag"
//Output: 5
//Explanation:
//
//As shown below, there are 5 ways you can generate "bag" from S.
//(The caret symbol ^ means the chosen letters)
//
//babgbag
//^^ ^
//babgbag
//^^    ^
//babgbag
//^    ^^
//babgbag
//  ^  ^^
//babgbag
//    ^^^
//


//Runtime: 12 ms, faster than 67.54% of C++ online submissions for Distinct Subsequences.
//Memory Usage : 14.3 MB, less than 46.39% of C++ online submissions for Distinct Subsequences.

// Have to use long??? Really???
class Solution {
public:
	int numDistinct(string s, string t) {
		int sLen = s.size();
		int tLen = t.size();
		if (tLen == 0 || s == t) { return 1; }
		if (tLen > sLen) { return 0; }
		vector<vector<long>> vM(tLen + 1, vector<long>(sLen + 1, 1));
		for (int row = 1; row <= tLen; ++row) {
			for (int col = 0; col <= sLen; ++col) {
				if (col == 0) { vM[row][col] = 0; }
				else {
					if (t[row - 1] == s[col - 1]) { vM[row][col] = vM[row][col - 1] + vM[row - 1][col - 1]; }
					else { vM[row][col] = vM[row][col - 1]; }
				}
			}
		}
		return vM[tLen][sLen];
	}
};