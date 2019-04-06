//Implement int sqrt(int x).
//
//Compute and return the square root of x, where x is guaranteed to be a non - negative integer.
//
//Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.
//
//Example 1:
//
//Input: 4
//	Output : 2
//
//	Example 2 :
//
//	Input : 8
//	Output : 2
//	Explanation : The square root of 8 is 2.82842..., and since
//	the decimal part is truncated, 2 is returned.
//


//Runtime: 56 ms, faster than 5.10% of C++ online submissions for Sqrt(x).
//Memory Usage : 8.2 MB, less than 99.48% of C++ online submissions for Sqrt(x).

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1) { return x; }
		else {
			double i = 1;
			while (i*i <= x) { ++i; }
			return --i;
		}
	}
};