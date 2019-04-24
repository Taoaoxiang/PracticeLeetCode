#include "include_LeetCode.h"



class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0) { return 0; }
		int p = 1, pp = 0;
		for (int i = 0; i < s.size(); ++i) {
			int cur = 0;
			if (s[i] != '0') { cur = p; }
			if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))) {
				cur += pp;
			}
			pp = p;
			p = cur;
		}
		return p;
	}
};





int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}