//Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
//Note: For the purpose of this problem, we define empty string as valid palindrome.
//
//Example 1:
//
//Input: "A man, a plan, a canal: Panama"
//Output: true
//
//Example 2:
//
//Input: "race a car"
//Output: false


//Runtime: 8 ms, faster than 99.29% of C++ online submissions for Valid Palindrome.
//Memory Usage : 9.4 MB, less than 19.13% of C++ online submissions for Valid Palindrome.

class Solution {
public:
	bool isPalindrome(string s) {
		int iL = 0, iR = s.size() - 1;
		while (iL < iR) {
			while (isalnum(s[iL]) == false && iL < iR) { ++iL; }
			while (isalnum(s[iR]) == false && iL < iR) { --iR; }
			if (toupper(s[iL]) != toupper(s[iR])) { return false; }
			++iL;
			--iR;
		}
		return true;
	}
};

//Runtime: 12 ms, faster than 79.06% of C++ online submissions for Valid Palindrome.
//Memory Usage : 9.2 MB, less than 35.52% of C++ online submissions for Valid Palindrome.

class Solution {
public:
	bool isPalindrome(string s) {
		int iL = 0, iR = s.size() - 1;
		while (iL < iR) {
			if ((s[iL] < '0' || (s[iL] > '9' && s[iL] < 'A')) || (s[iL] > 'z') || (s[iL] > 'Z' && s[iL] < 'a')) {
				++iL;
				continue;
			}
			if ((s[iR] < '0' || (s[iR] > '9' && s[iR] < 'A')) || (s[iR] > 'z') || (s[iR] > 'Z' && s[iR] < 'a')) {
				--iR;
				continue;
			}
			//cout << "Left=>" << s[iL] << ", Right=>" << s[iR] << endl;
			if ((s[iL] >= '0' && s[iL] <= '9') && (s[iL] != s[iR])) { return false; }
			else if (s[iL] >= 'A' && s[iL] <= 'Z') {
				if (s[iL] != s[iR] && s[iL] + 32 != s[iR]) { return false; }
			}
			else if (s[iL] >= 'a' && s[iL] <= 'z') {
				if (s[iL] != s[iR] && s[iL] - 32 != s[iR]) { return false; }
			}
			++iL;
			--iR;
		}
		return true;
	}
};