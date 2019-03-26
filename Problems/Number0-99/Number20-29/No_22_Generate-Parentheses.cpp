//Given n pairs of parentheses, write a function to generate all combinations of well - formed parentheses.
//
//For example, given n = 3, a solution set is :
//
//[
//	"((()))",
//	"(()())",
//	"(())()",
//	"()(())",
//	"()()()"
//]


//Runtime: 8 ms, faster than 98.43% of C++ online submissions for Generate Parentheses.
//Memory Usage : 17.3 MB, less than 44.54% of C++ online submissions for Generate Parentheses.

class Solution {
public:
	bool recursiveGen(string str, int iCompletePair, int iTotal, int iLeft, int iToZero, vector<string> &rtn) {
		if (iCompletePair == iTotal) {
			rtn.push_back(str);
			return true;
		}
		else {
			if (iLeft > iTotal || iToZero > 0) { return false; }
			else if (iToZero == 0) { return recursiveGen((str + '('), iCompletePair, iTotal, iLeft + 1, iToZero - 1, rtn); }
			else if (iToZero < 0) {
				if (iLeft < iTotal) { return recursiveGen((str + '('), iCompletePair, iTotal, iLeft + 1, iToZero - 1, rtn) && recursiveGen((str + ')'), iCompletePair + 1, iTotal, iLeft, iToZero + 1, rtn); }
				else if (iLeft == iTotal) { return recursiveGen((str + ')'), iCompletePair + 1, iTotal, iLeft, iToZero + 1, rtn); }
			}
		}
		return false;
	}

	vector<string> generateParenthesis(int n) {
		vector<string> rtn;
		recursiveGen("", 0, n, 0, 0, rtn);
		return rtn;
	}
};