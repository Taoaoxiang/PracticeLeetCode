//Given a string s1, we may represent it as a binary tree by partitioning it to two non - empty substrings recursively.
//
//Below is one possible representation of s1 = "great":
//
//great
/// \
//gr    eat
/// \ / \
//g   r  e   at
/// \
//a   t
//
//To scramble the string, we may choose any non - leaf node and swap its two children.
//
//For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
//
//rgeat
/// \
//rg    eat
/// \ / \
//r   g  e   at
/// \
//a   t
//
//We say that "rgeat" is a scrambled string of "great".
//
//Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
//
//rgtae
/// \
//rg    tae
/// \ / \
//r   g  ta  e
/// \
//t   a
//
//We say that "rgtae" is a scrambled string of "great".
//
//Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
//
//Example 1:
//
//Input: s1 = "great", s2 = "rgeat"
//	Output : true
//
//	Example 2 :
//
//	Input : s1 = "abcde", s2 = "caebd"
//	Output : false
//


//Runtime: 20 ms, faster than 35.12% of C++ online submissions for Scramble String.
//Memory Usage : 10.8 MB, less than 61.90% of C++ online submissions for Scramble String.

// It was really wierd that if not compare the sorted substring, 
// "Run Code" will tell me TLE, while it was totally fine in playground with 4ms.
class Solution {
public:
	bool reScramble(string s1, string s2) {
		if ((s1.size() != s2.size()) || (s1.size() == 0) || (s2.size() == 0)) { return false; }
		if (s1 == s2) { return true; }
		string ss1 = s1;
		string ss2 = s2;
		sort(ss1.begin(), ss1.end());
		sort(ss2.begin(), ss2.end());
		if (ss1 != ss2) {
			return false;
		}
		for (int i = 1; i < s1.size(); ++i) {
			if (reScramble(s1.substr(0, i), s2.substr(0, i)) &&
				reScramble(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i))) {
				return true;
			}
			if (reScramble(s1.substr(0, i), s2.substr(s2.size() - i, i)) &&
				reScramble(s1.substr(i, s1.size() - i), s2.substr(0, s2.size() - i))) {
				return true;
			}
		}
		return false;
	}

	bool isScramble(string s1, string s2) {
		return reScramble(s1, s2);
	}
};