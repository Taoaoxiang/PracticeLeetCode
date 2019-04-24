//Given a string containing digits from 2 - 9 inclusive, return all possible letter combinations that the number could represent.
//
//A mapping of digit to letters(just like on the telephone buttons) is given below.Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//	Output : ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//	Note :
//
//	Although the above answer is in lexicographical order, your answer could be in any order you want.
//

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
//Memory Usage : 8.5 MB, less than 91.83% of C++ online submissions for Letter Combinations of a Phone Number.

class Solution {
public:
	map<char, string> numToLetter = {
			{'2', "abc"},
			{'3', "def"},
			{'4', "ghi"},
			{'5', "jkl"},
			{'6', "mno"},
			{'7', "pqrs"},
			{'8', "tuv"},
			{'9', "wxyz"},
	};
	map<char, int> numLen = {
			{'2', 3},
			{'3', 3},
			{'4', 3},
			{'5', 3},
			{'6', 3},
			{'7', 4},
			{'8', 3},
			{'9', 4},
	};

	void recursiveAdd(string str, char currentDigit, int posInDigits, string digits, int lenDigits, vector<string> &rtn) {
		for (int i = 0; i != numLen[currentDigit];++i) {
			string str2 = str + numToLetter[currentDigit][i];
			if (posInDigits == lenDigits - 1) { rtn.push_back(str2); }
			else { recursiveAdd(str2, digits[posInDigits + 1], posInDigits + 1, digits, lenDigits, rtn); }
		}
		return;
	}

	vector<string> letterCombinations(string digits) {
		vector<string> rtn;
		if (digits.length() == 0) { return rtn; }
		else {
			int lenDigits = digits.length();
			//recursiveAdd(string str, char currentDigit, int posInDigits, int lenDigits, vector<string> &rtn);
			recursiveAdd("", digits[0], 0, digits, lenDigits, rtn);
		}
		return rtn;
	}
};