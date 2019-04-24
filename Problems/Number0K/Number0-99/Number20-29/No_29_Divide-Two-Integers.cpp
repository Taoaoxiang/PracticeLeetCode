//Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
//Return the quotient after dividing dividend by divisor.
//
//The integer division should truncate toward zero.
//
//Example 1:
//
//Input: dividend = 10, divisor = 3
//	Output : 3
//
//	Example 2 :
//
//	Input : dividend = 7, divisor = -3
//	Output : -2
//
//	Note :
//
//	Both dividend and divisor will be 32 - bit signed integers.
//	The divisor will never be 0.
//	Assume we are dealing with an environment which could only store integers within the 32 - bit signed integer range : [−231, 231 − 1].For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//


//Runtime: 12 ms, faster than 98.11% of C++ online submissions for Divide Two Integers.
//Memory Usage : 8.3 MB, less than 99.38% of C++ online submissions for Divide Two Integers.

// Not that nice version.
class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == 0) { return 0; }
		if (divisor == 1) { return dividend; }
		else if (divisor == -1) {
			if (dividend == pow(-2, 31)) { return (pow(2, 31) - 1); }
			else { return -dividend; }
		}
		long ldividend = dividend, ldivisor = divisor;
		int signFinal = 1;
		int result = 0;
		long unsigned_dividend = 0;
		long unsigned_divisor = 0;
		if (ldividend < 0) {
			signFinal *= -1;
			unsigned_dividend = -ldividend;
		}
		else { unsigned_dividend = ldividend; }
		if (ldivisor < 0) {
			signFinal *= -1;
			unsigned_divisor = -ldivisor;
		}
		else { unsigned_divisor = ldivisor; }
		while (unsigned_dividend >= unsigned_divisor) {
			long tmp_divisor = unsigned_divisor, tmp_pos = 1;
			while ((tmp_divisor << 1) <= unsigned_dividend) {
				tmp_divisor <<= 1;
				tmp_pos <<= 1;
			}
			unsigned_dividend -= tmp_divisor;
			result += tmp_pos;
		}
		result *= signFinal;

		return result;
	}
};