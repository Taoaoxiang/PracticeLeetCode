//The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//P   A   H   N
//A P L S I I G
//Y   I   R
//
//And then read line by line : "PAHNAPLSIIGYIR"
//
//Write the code that will take a string and make this conversion given a number of rows :
//
//string convert(string s, int numRows);
//
//Example 1:
//
//Input: s = "PAYPALISHIRING", numRows = 3
//	Output : "PAHNAPLSIIGYIR"
//
//	Example 2 :
//
//	Input : s = "PAYPALISHIRING", numRows = 4
//	Output : "PINALSIGYAHRPI"
//	Explanation :
//
//	P     I    N
//	A   L S  I G
//	Y A   H R
//	P     I
//


class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;

		vector<string> vec_all;
		for (int i = 0; i != numRows;++i) {
			string tmp;
			vec_all.push_back(tmp);
		}
		for (int i = 0; i != s.size();++i) {
			int serie = 2 * numRows - 2;
			int ori_row = i % (serie);
			int fin_row;
			if (ori_row < numRows) { fin_row = ori_row; }
			else { fin_row = serie - ori_row; }
			vec_all[fin_row].push_back(s[i]);
		}
		string rtn;
		for (int i = 0; i != numRows;++i) { rtn += vec_all[i]; }
		
		return rtn;
	}
};
