//Given a string s, partition s such that every substring of the partition is a palindrome.
//
//Return all possible palindrome partitioning of s.
//
//Example:
//
//Input: "aab"
//Output:
//[
//  ["aa","b"],
//  ["a","a","b"]
//]
//


//Runtime: 72 ms, faster than 28.91% of C++ online submissions for Palindrome Partitioning.
//Memory Usage : 25.6 MB, less than 44.45% of C++ online submissions for Palindrome Partitioning.

class Solution {
public:
	vector<vector<string>> rtn;
	vector<string> vec;
	void reS(int pos, string& sss) {
		if (pos >= sss.size()) {
			rtn.push_back(vec);
			return;
		}
		for (int i = pos; i < sss.size(); ++i) {
			string s1 = sss.substr(pos, i - pos + 1);
			string s2(s1);
			reverse(s2.begin(), s2.end());
			if (s1 == s2) {
				vec.push_back(s1);
				reS(i + 1);
				vec.pop_back();
			}
		}
		return;
	}

	vector<vector<string>> partition(string s) {
		if (s.size() == 0) { return rtn; }
		reS(0, s);
		return rtn;
	}
};