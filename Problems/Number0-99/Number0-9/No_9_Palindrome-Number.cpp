//Determine whether an integer is a palindrome.An integer is a palindrome when it reads the same backward as forward.
//
//Example 1:
//
//Input: 121
//	Output : true
//
//	Example 2 :
//
//	Input : -121
//	Output : false
//	Explanation : From left to right, it reads - 121. From right to left, it becomes 121 - .Therefore it is not a palindrome.
//
//	Example 3 :
//
//	Input : 10
//	Output : false
//	Explanation : Reads 01 from right to left.Therefore it is not a palindrome.

// This one is not that fast, maybe other people convert it to string first? :P

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) { return false; }
		else if (x == 0) { return true; }
		else {
			int lim_max = pow(2, 31) - 1;
			long rev = 0;
			int x2 = x;
			while (x2 != 0) {
				rev = 10 * rev + x2 % 10;
				x2 /= 10;
			}
			if (rev > lim_max) { return false; }
			if (rev == x) { return true; }
			return false;
		}
	}
};