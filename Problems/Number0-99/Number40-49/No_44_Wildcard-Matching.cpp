//Given an input string(s) and a pattern(p), implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters(including the empty sequence).
//
//The matching should cover the entire input string(not partial).
//
//Note:
//
//s could be empty and contains only lowercase letters a - z.
//p could be empty and contains only lowercase letters a - z, and characters like ? or *.
//
//Example 1 :
// 
//	Input :
//	s = "aa"
//	p = "a"
//	Output : false
//	Explanation : "a" does not match the entire string "aa".
//
//	Example 2 :
//
//	Input :
//	s = "aa"
//	p = "*"
//	Output : true
//	Explanation : '*' matches any sequence.
//
//	Example 3 :
//
//	Input :
//	s = "cb"
//	p = "?a"
//	Output : false
//	Explanation : '?' matches 'c', but the second letter is 'a', which does not match 'b'.
//
//	Example 4 :
//
//	Input :
//	s = "adceb"
//	p = "*a*b"
//	Output : true
//	Explanation : The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
//
//	Example 5 :
//
//	Input :
//	s = "acdcb"
//	p = "a*c?b"
//	Output : false
//
//



// So I tried recursion first, but the submission always gave me Time Limit Exceeded, which I could totally get result on my laptop.
// Anyway then I have to check what other people do. 
// Dynamic programming, lesson learnt
// Thank you for your contribution (haoel/leetcode).
//
//Runtime: 12 ms
//Memory Usage : 8.9 MB
// I remove the continuous duplicate asterisk first.
// It's faster than the normal version.
class Solution {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size();
		int pSize = p.size();
		if (sSize == 0 && pSize == 0) { return true; }
		else if (sSize != 0 && pSize == 0) { return false; }
		else {
			string pCut = "";
			for (int i = 0; i < p.size();++i) {
				if (p[i] != '*') { pCut += p[i]; }
				else {
					if (i == 0) { pCut += p[i]; }
					else if (p[i] != p[i - 1]) { pCut += p[i]; }
					else { continue; }
				}
			}
			p = pCut;
			pSize = p.size();
			int posMarkS = -1;
			int posMarkP = -1;
			int posS = 0, posP = 0;
			while (posS < sSize) {
				if (p[posP] == '*') {
					++posP;
					if (posP >= pSize) { return true; }
					posMarkP = posP;
					posMarkS = posS;
				}
				else if (p[posP] == s[posS] || p[posP] == '?') {
					++posP;
					++posS;
				}
				else if (posMarkS != -1) {
					posS = ++posMarkS;
					posP = posMarkP;
				}
				else { return false; }
			}
			while (p[posP] == '*') { ++posP; }
			if (posP >= pSize) { return true; }
			else { return false; }
		}
	}
};

//Runtime: 20 ms, faster than 96.58% of C++ online submissions for Wildcard Matching.
//Memory Usage : 8.8 MB, less than 99.66% of C++ online submissions for Wildcard Matching.
// normal version, comment out the duplicate removal part
class Solution {
public:
	bool isMatch(string s, string p) {
		int sSize = s.size();
		int pSize = p.size();
		if (sSize == 0 && pSize == 0) { return true; }
		else if (sSize != 0 && pSize == 0) { return false; }
		else {
			//string pCut="";
			//for (int i = 0; i < p.size();++i) {
			//	if (p[i] != '*') { pCut += p[i]; }
			//	else {
			//		if (i == 0) { pCut += p[i]; }
			//		else if (p[i] != p[i - 1]) { pCut += p[i]; }
			//		else { continue; }
			//	}
			//}
			//p = pCut;
			//pSize = p.size();
			int posMarkS = -1;
			int posMarkP = -1;
			int posS = 0, posP = 0;
			while (posS < sSize) {
				if (p[posP] == '*') {
					++posP;
					if (posP >= pSize) { return true; }
					posMarkP = posP;
					posMarkS = posS;
				}
				else if (p[posP] == s[posS] || p[posP] == '?') {
					++posP;
					++posS;
				}
				else if (posMarkS != -1) {
					posS = ++posMarkS;
					posP = posMarkP;
				}
				else { return false; }
			}
			while (p[posP] == '*') { ++posP; }
			if (posP >= pSize) { return true; }
			else { return false; }
		}
	}
};

