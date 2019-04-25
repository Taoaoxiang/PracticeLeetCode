#include "include_LeetCode.h"



class Solution {
public:
	bool isPalindrome(string s) {
		int iL = 0, iR = s.size() - 1;
		while (iL < iR) {
			while (isalnum(s[iL]) == false && iL < iR) { ++iL; }
			while (isalnum(s[iR]) == false && iL < iR) { --iR; }
			if (toupper(s[iL]) != toupper(s[iR])) { return false; }
			++iL;
			--iR;
		}
		return true;
	}
};


int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}