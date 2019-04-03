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
	bool isMatch(string s, string p) {
		int sSize = s.size();
		int pSize = p.size();
		if (sSize == 0 && pSize == 0) { return true; }
		else if (sSize != 0 && pSize == 0) { return false; }
		else { 
			string pCut="";
			for (int i = 0; i < p.size();++i) {
				if (p[i] != '*') { pCut += p[i]; }
				else {
					if (i == 0) { pCut += p[i]; }
					else if (p[i] != p[i - 1]) { pCut += p[i]; }
					else { continue; }
				}
			}
			p = pCut;
			pSize = p.size();
			int posMarkS = -1;
			int posMarkP = -1;
			int posS = 0, posP = 0;
			while (posS < sSize) {
				if (p[posP] == '*') {
					++posP;
					if (posP >= pSize) { return true; }
					posMarkP = posP;
					posMarkS = posS;
				} 
				else if (p[posP] == s[posS] || p[posP] == '?') { 
					++posP; 
					++posS; 
				}
				else if (posMarkS != -1) {
					posS = ++posMarkS;
					posP = posMarkP;
				}
				else { return false; }
			}
			while (p[posP] == '*') { ++posP; }
			if (posP >= pSize) { return true; }
			else { return false; }
		}
	}
};

int main() {

	string s = "babaaababaabababbbbbbaabaabbabababbaababbaaabbbaaab";
		
	string p = "***bba**a*bbba**aab**b";
	s = "adceb";
	p = "*a*b";

	s = "aaabaaabaabababbabababaababbabbbbaaaaababbaabbbaab";
	p = "*babbbb*aab**b*bb*aa*";
	s = "bbbbbbbabbaabbabbbbaaabbabbabaaabbababbbabbbabaaabaab";
	p = "b*b*ab**ba*b**b***bba";


	bool ret = Solution().isMatch(s, p);

	cout << ret << endl;

	std::cout << "Wuzup world!" << std::endl;
	return 0;
}