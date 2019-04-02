//Given two non - negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
//Example 1:
//
//Input: num1 = "2", num2 = "3"
//	Output : "6"
//
//	Example 2 :
//
//	Input : num1 = "123", num2 = "456"
//	Output : "56088"
//
//	Note :
//
//	The length of both num1 and num2 is < 110.
//	Both num1 and num2 contain only digits 0 - 9.
//	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
//	You must not use any built - in BigInteger library or convert the inputs to integer directly.
//
//


//Runtime: 8 ms, faster than 98.92% of C++ online submissions for Multiply Strings.
//Memory Usage : 9.5 MB, less than 100.00% of C++ online submissions for Multiply Strings.

class Solution {
public:
	string multiply(string num1, string num2) {
		if (num1.size() == 0 || num2.size() == 0) { return ""; }
		if (num1[0] == '0' || num2[0] == '0') { return "0"; }
		string rtn = "";
		int remain = 0;
		int pos1, pos2;
		for (int digit = 0; digit < num1.size() + num2.size() - 1; ++digit) {
			int result = remain;
			for (int i1 = 0, i2 = digit; i1 <= digit, i2 >= 0; ++i1, --i2) {
				if (i2 > num2.size() - 1) { continue; }
				if (i1 > num1.size() - 1) { break; }
				pos1 = num1.size() - 1 - i1;
				pos2 = num2.size() - 1 - i2;
				result += ((num2[pos2] - '0') * (num1[pos1] - '0'));
			}

			char s = (result % 10) + '0';
			remain = (result / 10);
			rtn = s + rtn;
		}
		if (remain != 0) {
			char s = remain + '0';
			rtn = s + rtn;
		}

		return rtn;
	}
};