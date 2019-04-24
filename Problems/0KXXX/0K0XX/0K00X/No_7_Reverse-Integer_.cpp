//Given a 32 - bit signed integer, reverse digits of an integer.
//
//Example 1:
//
//Input: 123
//	Output : 321
//
//	Example 2 :
//
//	Input : -123
//	Output : -321
//
//	Example 3 :
//
//	Input : 120
//	Output : 21
//
// Looks like this solution is fast this time :)

class Solution {
public:
	int reverse(int x) {
		int sign = 1;
		int rtn;
		long tmp_i = x;
		long li = 0;
		if (x < 0) {
			sign *= -1;
			tmp_i *= -1;
		}
		else if (x == 0) { return 0; }
		long digit = pow(10, 9);
		long digit2 = 1;
		while (tmp_i / digit == 0) { digit /= 10; }
		while (digit != 0) {
			li = li + (tmp_i / digit)*digit2;
			tmp_i = tmp_i % digit;
			digit /= 10;
			digit2 *= 10;
		}
		li *= sign;
		if (li > (pow(2, 31) - 1) || li < (pow(-2, 31))) { return 0; }
		else { rtn = li; }
		//cout << x << '\n'<<li << endl;
		return rtn;
	}
};