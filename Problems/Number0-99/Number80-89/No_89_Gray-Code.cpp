//The gray code is a binary numeral system where two successive values differ in only one bit.
//
//Given a non - negative integer n representing the total number of bits in the code, print the sequence of gray code.A gray code sequence must begin with 0.
//
//Example 1:
//
//Input: 2
//	Output : [0, 1, 3, 2]
//	Explanation :
//	00 - 0
//	01 - 1
//	11 - 3
//	10 - 2
//
//	For a given n, a gray code sequence may not be uniquely defined.
//	For example, [0, 2, 3, 1] is also a valid gray code sequence.
//
//	00 - 0
//	10 - 2
//	11 - 3
//	01 - 1
//
//	Example 2:
//
//   Input: 0
//	   Output : [0]
//	   Explanation : We define the gray code sequence to begin with 0.
//	   A gray code sequence of n has size = 2n, which for n = 0 the size is 20 = 1.
//	   Therefore, for n = 0 the gray code sequence is[0].
//


//Runtime: 8 ms, faster than 47.82% of C++ online submissions for Gray Code.
//Memory Usage : 8.6 MB, less than 62.74% of C++ online submissions for Gray Code.

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> rtn;
		int iAll = pow(2, n);
		for (int i = 0; i < iAll;++i) {
			int iEx = iAll / 2;
			int r = 0;
			int iRemain = i;
			while (iRemain > 0) {
				if (iRemain >= iEx) {
					r += iEx;
					iRemain = 2 * iEx - 1 - iRemain;
				}
				iEx /= 2;
			}
			rtn.push_back(r);
		}
		return rtn;
	}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Gray Code.
//Memory Usage : 8.5 MB, less than 90.20% of C++ online submissions for Gray Code.

class Solution {
public:
	vector<int> grayCode(int n) {
		vector<int> rtn = { 0 };
		for (int i = 0; i < n;++i) {
			int ex = pow(2, i);
			for (int pos = ex - 1; pos >= 0;--pos) { rtn.push_back(ex + rtn[pos]); }
		}
		return rtn;
	}
};
