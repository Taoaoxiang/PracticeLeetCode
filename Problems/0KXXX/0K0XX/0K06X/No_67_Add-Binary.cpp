//Given two binary strings, return their sum(also a binary string).
//
//The input strings are both non - empty and contains only characters 1 or 0.
//
//Example 1:
//
//Input: a = "11", b = "1"
//	Output : "100"
//
//	Example 2 :
//
//	Input : a = "1010", b = "1011"
//	Output : "10101"
//
//

//Runtime: 12 ms, faster than 16.26% of C++ online submissions for Add Binary.
//Memory Usage : 9.3 MB, less than 8.05% of C++ online submissions for Add Binary.

class Solution {
public:
	string addBinary(string a, string b) {
		string rtn;
		int i = a.size() - 1, j = b.size() - 1;
		int re = 0;
		for (; i >= 0 && j >= 0; --i, --j) {
			if (re == 0) {
				if (a[i] == '0' && b[j] == '0') { rtn = "0" + rtn; }
				else if (a[i] == '1' && b[j] == '1') {
					rtn = "0" + rtn;
					re = 1;
				}
				else { rtn = "1" + rtn; }
			}
			else {
				if (a[i] == '0' && b[j] == '0') {
					rtn = "1" + rtn;
					re = 0;
				}
				else if (a[i] == '1' && b[j] == '1') { rtn = "1" + rtn; }
				else { rtn = "0" + rtn; }
			}
		}
		if (i < 0 && j < 0) {
			if (re == 1) {
				rtn = "1" + rtn;
				re = 0;
			}
		}
		else if (i < 0 && j >= 0) {
			for (;j >= 0;--j) {
				if (re == 1) {
					if (b[j] == '1') { rtn = "0" + rtn; }
					else {
						rtn = "1" + rtn;
						re = 0;
					}
				}
				else { rtn = b[j] + rtn; }
			}
		}
		else if (i >= 0 && j < 0) {
			for (;i >= 0;--i) {
				if (re == 1) {
					if (a[i] == '1') { rtn = "0" + rtn; }
					else {
						rtn = "1" + rtn;
						re = 0;
					}
				}
				else { rtn = a[i] + rtn; }
			}
		}

		if (re == 1) { rtn = "1" + rtn; }
		return rtn;
	}
};