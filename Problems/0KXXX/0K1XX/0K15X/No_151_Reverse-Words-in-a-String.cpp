//Given an input string, reverse the string word by word.
//
// 
//
//Example 1:
//
//Input: "the sky is blue"
//Output: "blue is sky the"
//
//Example 2:
//
//Input: "  hello world!  "
//Output: "world! hello"
//Explanation: Your reversed string should not contain leading or trailing spaces.
//
//Example 3:
//
//Input: "a good   example"
//Output: "example good a"
//Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
//
// 
//
//Note:
//
//    A word is defined as a sequence of non-space characters.
//    Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
//    You need to reduce multiple spaces between two words to a single space in the reversed string.
//
// 
//
//Follow up:
//
//For C programmers, try to solve it in-place in O(1) extra space.

//Runtime: 8 ms, faster than 99.69% of C++ online submissions for Reverse Words in a String.
//Memory Usage : 67 MB, less than 8.22% of C++ online submissions for Reverse Words in a String.

class Solution {
public:
	string reverseWords(string s) {
		string rtn = "", sLast = "";
		int pos1 = s.find_first_not_of(' ', 0);
		int pos0 = s.find_first_of(' ', pos1);
		while (pos0 != string::npos || pos1 != string::npos) {
			rtn = s.substr(pos1, pos0 - pos1) + " " + rtn;
			pos1 = s.find_first_not_of(' ', pos0);
			pos0 = s.find_first_of(' ', pos1);
		}

		return rtn.substr(0, rtn.size() - 1);
	}
};


//Runtime: 44 ms, faster than 13.17% of C++ online submissions for Reverse Words in a String.
//Memory Usage : 67.1 MB, less than 8.22% of C++ online submissions for Reverse Words in a String.

class Solution {
public:
	string reverseWords(string s) {
		string rtn = "";
		while (s.size() > 0) {
			int pos = s.find(' ');
			if (pos == string::npos) {
				rtn = s + " " + rtn;
				s.clear();
			}
			else if (pos == 0) {
				s.erase(s.begin() + pos);
			}
			else {
				rtn = s.substr(0, pos) + " " + rtn;
				s.erase(s.begin(), s.begin() + pos + 1);
			}
		}
		return rtn.substr(0, rtn.size() - 1);
	}
};