#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;

class Solution {
public:
	int numDecodings(string s) {
		
		int sSize = s.size();
		if (sSize == 0) { return 0; }
		else if (sSize == 1) { 
			if (s[0] == '0') { return 0; } 
			else { return 1; }
		}
		int rtn = 0;
		for (int i = 0; i < sSize; ++i) {
			if (i == 0) {
				if (s[i] == '0') { return 0; }
				else if (s[i] == '1') { rtn += 2; }
				else if (s[i] == '2') { 
					if (s[i + 1] >= '0' && s[i + 1] <= '6') { rtn += 2; }
					else { rtn += 1; }
				}
				else { rtn += 1; }
			}
			else if (i == sSize - 1) {
				if (s[i] == '0') {
					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
					else { return 0; }
				}
				else {
					if (s[i - 1] == '1') { rtn += 2; }
					else if (s[i - 1] == '2' && (s[i] >= '1'&&s[i] <= '6')) { rtn += 2; }
					else { rtn += 1; }
				}
			}
			else {
				if (s[i] == '0') {
					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
					else { return 0; }
				}
				else if (s[i] == '1') { 
					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 3; }
					else { rtn += 2; }
				}
				else if (s[i] == '2') {
					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
					if (s[i + 1] >= '0' && s[i + 1] <= '6') { rtn += 1; }
					rtn += 1;
				}
				else { 
					if (s[i - 1] == '1' ) { rtn += 2; } 
					else if (s[i - 1] == '2' && (s[i]>='1'&&s[i] <= '6')) { rtn += 2; }
					else { rtn += 1; }
				}
			}
		}
		return rtn-sSize-1;
	}
};






int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}