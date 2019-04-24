//Given a string s, find the longest palindromic substring in s.You may assume that the maximum length of s is 1000.
//
//Example 1:
//
//Input: "babad"
//	Output : "bab"
//	Note : "aba" is also a valid answer.
//
//	Example 2 :
//
//	Input : "cbbd"
//	Output : "bb"
//
//


//// This solution has "Time Limit Exceed" problem
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int m, n, l;
//		string rtn;
//		for (int i = 0;i < s.size();++i) {
//			for (int i2 = s.size() - 1; i2 >= i;--i2) {
//				if (s[i] == s[i2]) {
//					l = i2 - i + 1;
//					if (l % 2 == 0) {
//						for (m = (i + i2) / 2, n = (i + i2) / 2 + 1; m >= i || n <= i2; --m, ++n) {
//							if (s[m] == s[n]) { 
//								std::cout << "T2: " << i << " ... " << l << std::endl;
//								if (i >= m - 1 && i2 <= n + 1) {
//									std::cout << "T1: " << i << " ... " << l << std::endl;
//									if (rtn.size() < l) { rtn = s.substr(i, l); } } }
//							else { break; }
//						}
//					}
//					else {
//						for (m = (i + i2) / 2, n = (i + i2) / 2;m >= i || n <= i2; --m, ++n) {
//							if (s[m] == s[n]) { if (i >= m - 1 && i2 <= n + 1) { if (rtn.size() < l) { rtn = s.substr(i, l); } } }
//							else { break; }
//						}
//					}
//				}
//			}
//		}
//		return rtn;
//	}
//};
//
//// This solution is "Memory Limit Exceeded"
//class Solution {
//public:
//	string longestPalindrome(string s) {
//		int MAXSTR = 1000;
//		string rtn;
//		string s_sub, s_sub_r;
//		rtn.reserve(MAXSTR);
//		s_sub.reserve(MAXSTR);
//		s_sub_r.reserve(MAXSTR);
//		for (int i = 0;i < s.size();++i) {
//			for (int i2 = s.size() - 1; i2 >= i;--i2) {
//				if (s[i] == s[i2]) {
//					s_sub = s.substr(i, i2 - i + 1);
//					s_sub_r=s_sub;
//					std::reverse(s_sub_r.begin(), s_sub_r.end());
//					if (s_sub.compare(s_sub_r) == 0) {
//						if (rtn.size() <= s_sub.size()) { rtn = s_sub; }
//						break;
//					}
//				}
//			}
//		}
//		return rtn;
//	}
//};

// Finally this one works!
// Runtime: 196 ms, faster than 30.61% of C++ online submissions for Longest Palindromic Substring.
// Memory Usage : 9.6 MB, less than 66.55% of C++ online submissions for Longest Palindromic Substring.
class Solution {
public:
	string longestPalindrome(string s) {
		int m, n;
		string rtn;
		rtn.reserve(1000);
		for (int i = 0;i < s.size();++i) {
			if (rtn.size() >= (s.size() - i)) { break; }
			else {
				for (int i2 = s.size() - 1; i2 >= i;--i2) {
					if (rtn.size() > (i2 - i + 1)) { break; }
					else {
						m = i;
						n = i2;
						while (s[m] == s[n]) {
							if (m >= n) {
								rtn = s.substr(i, i2 - i + 1);
								break;
							}
							++m;
							--n;
						}

					}
				}
			}
		}
		return rtn;
	}
};