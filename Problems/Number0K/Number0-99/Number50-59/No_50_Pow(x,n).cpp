//Implement pow(x, n), which calculates x raised to the power n(xn).
//
//Example 1:
//
//Input: 2.00000, 10
//	Output : 1024.00000
//
//	Example 2 :
//
//	Input : 2.10000, 3
//	Output : 9.26100
//
//	Example 3 :
//
//	Input : 2.00000, -2
//	Output : 0.25000
//	Explanation : 2 - 2 = 1 / 22 = 1 / 4 = 0.25
//
//	Note :
//
//	-100.0 < x < 100.0
//	n is a 32 - bit signed integer, within the range[−231, 231 − 1]
//
//

//Runtime: 8 ms, faster than 70.01% of C++ online submissions for Pow(x, n).
//Memory Usage : 8.4 MB, less than 100.00% of C++ online submissions for Pow(x, n).

// This is okay solution, I guess.
class Solution {
public:
	double myPow(double x, int n) {
		if (n == 0 || x == 1) { return 1; }
		else if (n == 1) { return x; }
		else if (n == -1) { return (1 / x); }
		else if (x == -1) {
			if (n % 2 == 0) { return 1; }
			else { return -1; }
		}
		double nLong = n;
		double nUnsign = 0;
		if (nLong < 0) { nUnsign = -nLong; }
		else { nUnsign = nLong; }
		double rtn = 1;

		while (nUnsign > 0) {
			double maxEx = 1;
			double maxX = x;
			while ((maxEx * 2) <= nUnsign) {
				maxEx *= 2;
				maxX *= maxX;
			}
			if (maxEx == 1) {
				rtn *= x;
				break;
			}
			nUnsign -= maxEx;
			rtn *= maxX;
			//cout << "T1: left=> " << nUnsign << endl;
		}
		if (nLong > 0) { return rtn; }
		else { return (1 / rtn); }
	}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Pow(x, n).
//Memory Usage : 8.4 MB, less than 100.00% of C++ online submissions for Pow(x, n).

// Well, this works, right?
class Solution {
public:
	double myPow(double x, int n) { return pow(x, n); }
};