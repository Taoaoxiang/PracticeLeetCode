//Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully(left and right) justified.
//
//You should pack your words in a greedy approach; that is, pack as many words as you can in each line.Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
//
//Extra spaces between words should be distributed as evenly as possible.If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
//
//For the last line of text, it should be left justified and no extra space is inserted between words.
//
//Note:
//
//A word is defined as a character sequence consisting of non - space characters only.
//Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//The input array words contains at least one word.
//
//Example 1:
//
//Input:
//words = ["This", "is", "an", "example", "of", "text", "justification."]
//maxWidth = 16
//Output :
//	[
//		"This    is    an",
//		"example  of text",
//		"justification.  "
//	]
//
//Example 2:
//
//Input:
//words = ["What", "must", "be", "acknowledgment", "shall", "be"]
//maxWidth = 16
//Output :
//	[
//		"What   must   be",
//		"acknowledgment  ",
//		"shall be        "
//	]
//Explanation : Note that the last line is "shall be    " instead of "shall     be",
//	because the last line must be left - justified instead of fully - justified.
//	Note that the second line is also left - justified becase it contains only one word.
//
//	Example 3 :
//
//	Input :
//	words = ["Science", "is", "what", "we", "understand", "well", "enough", "to", "explain",
//	"to", "a", "computer.", "Art", "is", "everything", "else", "we", "do"]
//	maxWidth = 20
//	Output :
//	[
//		"Science  is  what we",
//		"understand      well",
//		"enough to explain to",
//		"a  computer.  Art is",
//		"everything  else  we",
//		"do                  "
//	]
//


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Text Justification.
//Memory Usage : 9.6 MB, less than 5.94% of C++ online submissions for Text Justification.

// First try of submission accepted. :)
// And this is a hard case. ;p
class Solution {
public:
	int lenCheck(int iStart, int iEnd, vector<string>& words, int maxWidth) {
		if (iEnd >= words.size()) { return -1; }
		else {
			int len = iEnd - iStart;
			for (int i = iStart; i <= iEnd; ++i) { len += words[i].size(); }
			if (len > maxWidth) { return 0; }
			else { return 1; }
		}
	}

	string strGen(int iStart, int iEnd, vector<string>& words, int maxWidth) {
		string s = "";
		if (iStart == iEnd) { s = words[iStart] + string(maxWidth - words[iStart].size(), ' '); }
		else {
			int lenWord = 0;
			for (int i = iStart; i <= iEnd; ++i) { lenWord += words[i].size(); }
			int re = (maxWidth - lenWord) % (iEnd - iStart);
			int quo = (maxWidth - lenWord) / (iEnd - iStart);
			for (int i = iStart; i <= iEnd; ++i) {
				s += words[i];
				if (i != iEnd) { s += string(quo, ' '); }
				if (re != 0) {
					s += " ";
					--re;
				}
			}
		}
		return s;
	}

	void strRecursion(int iStart, int iEnd, vector<string>& words, int maxWidth, vector<string> &rtn) {
		int status;
		while ((status = lenCheck(iStart, iEnd, words, maxWidth)) > 0) { ++iEnd; }
		--iEnd;
		string s = "";
		if (status == -1) {
			for (int i = iStart; i <= iEnd; ++i) {
				s += words[i];
				if (i != iEnd) { s += " "; }
				else { s += string(maxWidth - s.size(), ' '); }
			}
			rtn.push_back(s);
			return;
		}
		else {
			s = strGen(iStart, iEnd, words, maxWidth);
			rtn.push_back(s);
			strRecursion(iEnd + 1, iEnd + 1, words, maxWidth, rtn);
			return;
		}
	}

	vector<string> fullJustify(vector<string>& words, int maxWidth) {
		if (words.size() == 1) { return { words[0] + string(maxWidth - words[0].size(),  ' ') }; }
		vector<string> rtn;
		strRecursion(0, 0, words, maxWidth, rtn);

		return rtn;
	}
};