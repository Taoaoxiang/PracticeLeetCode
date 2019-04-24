//The set[1, 2, 3, ..., n] contains a total of n!unique permutations.
//
//By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
//
//"123"
//"132"
//"213"
//"231"
//"312"
//"321"
//
//Given n and k, return the kth permutation sequence.
//
//Note:
//
//Given n will be between 1 and 9 inclusive.
//Given k will be between 1 and n!inclusive.
//
//Example 1 :
//
//	Input : n = 3, k = 3
//	Output : "213"
//
//	Example 2 :
//
//	Input : n = 4, k = 9
//	Output : "2314"
//


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Permutation Sequence.
//Memory Usage : 7.9 MB, less than 100.00% of C++ online submissions for Permutation Sequence.

// Minor change
class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 1) { return "1"; }
		string s, rtn = "";
		for (int i = 1; i <= n; ++i) { s += ('0' + i); }
		int iFact = 1;
		for (int i = n - 1; i >= 1; --i) { iFact *= i; }
		--k;
		while (--n > 0) {
			int quo = k / iFact;
			k = k % iFact;
			rtn += s[quo];
			s.erase(s.begin() + quo);
			iFact /= n;
		}
		rtn += s[0];
		return rtn;
	}
};

// Same speed? 
class Solution {
public:
	string getPermutation(int n, int k) {
		if (n == 1) { return "1"; }
		string s, rtn = "";
		for (int i = 1; i <= n; ++i) { s += ('0' + i); }
		int iFact = 1;
		for (int i = n - 1; i >= 1; --i) { iFact *= i; }
		--k;
		while (--n >= 0) {
			int quo = k / iFact;
			k = k % iFact;
			rtn += s[quo];
			s.erase(s.begin() + quo);
			if (n != 0) { iFact /= n; }
			else { iFact /= 1; }
		}
		return rtn;
	}
};