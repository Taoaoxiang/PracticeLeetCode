//Given a string s consists of upper / lower - case alphabets and empty space characters ' ', return the length of last word in the string.
//
//If the last word does not exist, return 0.
//
//Note: A word is defined as a character sequence consists of non - space characters only.
//
//	Example :
//
//	Input : "Hello World"
//	Output : 5
//

//Runtime: 12 ms, faster than 5.49% of C++ online submissions for Length of Last Word.
//Memory Usage : 8.6 MB, less than 100.00% of C++ online submissions for Length of Last Word.

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.size() == 0) { return 0; }
		int iLen = 0;
		for (int i = s.size() - 1; i >= 0; --i) {
			if (s[i] == ' ') {
				if (iLen != 0) { break; }
				else { continue; }
			}
			else { ++iLen; }
		}
		return iLen;
	}
};
