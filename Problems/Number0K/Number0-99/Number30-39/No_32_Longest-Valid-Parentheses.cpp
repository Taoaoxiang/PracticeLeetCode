//Given a string containing just the characters '(' and ')', find the length of the longest valid(well - formed) parentheses substring.
//
//Example 1:
//
//Input: "(()"
//	Output : 2
//	Explanation : The longest valid parentheses substring is "()"
//
//	Example 2 :
//
//	Input : ")()())"
//	Output : 4
//	Explanation : The longest valid parentheses substring is "()()"
//
//
//Runtime: 8 ms, faster than 98.94% of C++ online submissions for Longest Valid Parentheses.
//Memory Usage : 8.9 MB, less than 100.00% of C++ online submissions for Longest Valid Parentheses.

class Solution {
public:
	int longestValidParentheses(string s) {
		if (s.length() <= 1) { return 0; }
		// From here, we go forward and backword once, respectively.
		vector<int> vecAll;
		// Forward
		int iCtrl = 0, iPair = 0, iL = 0, iR = 0;
		for (int i = 0; i < s.length(); ++i) {
			if (s[i] == '(') {
				++iCtrl;
				++iL;
			}
			else if (s[i] == ')') {
				if (iCtrl != 0) {
					--iCtrl;
					++iR;
					++iPair;
					if (iL == iR) { vecAll.push_back(iPair * 2); }
				}
				else {
					iL = 0;
					iR = 0;
					iPair = 0;
				}
			}
			else {}
		}
		// Backward
		iCtrl = 0, iPair = 0, iL = 0, iR = 0;
		for (int i = s.length() - 1; i >= 0; --i) {
			if (s[i] == ')') {
				++iCtrl;
				++iR;
			}
			else if (s[i] == '(') {
				if (iCtrl != 0) {
					--iCtrl;
					++iL;
					++iPair;
					if (iL == iR) { vecAll.push_back(iPair * 2); }
				}
				else {
					iL = 0;
					iR = 0;
					iPair = 0;
				}
			}
			else {}
		}
		// Get the longest length.
		if (vecAll.size() == 0) { return 0; }
		else {
			int rtn = 0;
			for (int i = 0; i < vecAll.size(); ++i) {
				if (vecAll[i] > rtn) { rtn = vecAll[i]; }
			}
			return rtn;
		}
		return 0;
	}
};