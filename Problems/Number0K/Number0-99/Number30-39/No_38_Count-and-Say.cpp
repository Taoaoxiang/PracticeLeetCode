//The count - and-say sequence is the sequence of integers with the first five terms as following :
//
//1.     1
//2.     11
//3.     21
//4.     1211
//5.     111221
//
//1 is read off as "one 1" or 11.
//11 is read off as "two 1s" or 21.
//21 is read off as "one 2, then one 1" or 1211.
//
//Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count - and-say sequence.
//
//Note: Each term of the sequence of integers will be represented as a string.
//
//
//
//	Example 1 :
//
//	Input : 1
//	Output : "1"
//
//	Example 2 :
//
//	Input : 4
//	Output : "1211"



//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Count and Say.
//Memory Usage : 9.1 MB, less than 39.34% of C++ online submissions for Count and Say.

class Solution {
public:
	string genString(string str) {
		string rtn = "";
		char c;
		int iTime;
		for (int i = 0; i < str.length();++i) {
			if (i == 0) {
				c = str[i];
				iTime = 1;
			}
			else if (i == str.length() - 1) {
				if (str[i] == c) {
					++iTime;
					rtn += ('0' + iTime);
					rtn += c;
				}
				else {
					rtn += ('0' + iTime);
					rtn += c;
					rtn += '1';
					rtn += str[i];
				}
			}
			else {
				if (str[i] == c) { ++iTime; }
				else {
					rtn += ('0' + iTime);
					rtn += c;
					c = str[i];
					iTime = 1;
				}
			}
			//cout << "T00: iTime=>" << iTime << endl;
			//cout << "T0: " << rtn << endl;
		}
		return rtn;
	}

	string recursiveString(int pos, string str, int n) {
		if (pos == n) { return str; }
		else { return recursiveString(pos + 1, genString(str), n); }
	}

	string countAndSay(int n) {
		if (n == 1) { return "1"; }
		return recursiveString(2, "11", n);
	}
};