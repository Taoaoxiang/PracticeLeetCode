#include <iostream>
#include <string>
#include <vector>
#include <math.h>

using namespace std;



class Solution {
public:
	

	bool checkQuality(string &p, int p_len) {
		string s_wc= "";
		for (int i = 0; i != p_len;++i) {
			if ((p[i] >= 'a' && p[i] <= 'z') || (p[i] == '.')) { s_wc = p[i]; }
			else if (p[i] == '*') {
				if (s_wc.length() == 0) { return false; }
				else if (s_wc.back() == '*') { return false; }
				s_wc += p[i];
			}
			else { return false; }
		}
		return true;
	}

	struct ELEMENT_STRING
	{
		char c = '\0';
		int t_min = 0;
		bool t_max = true;
	};

	vector<ELEMENT_STRING> vectorize(string &p, int p_len) {
		vector<ELEMENT_STRING> rtn;
		int pos_next;
		int pos = 0;
		while (pos != p_len) {
			pos_next = pos + 1;
			if ((p[pos] >= 'a' && p[pos] <= 'z') || (p[pos] == '.')) {
				if (rtn.size() == 0) {
					ELEMENT_STRING tmp;
					tmp.c = p[pos];
					if ((pos_next != p_len) && (p[pos_next] == '*')) {
						tmp.t_max = false;
						++pos;
					}
					else { tmp.t_min += 1; }
					rtn.push_back(tmp);
				}
				else {
					ELEMENT_STRING& last = rtn.back();
					if (p[pos] != last.c) {
						ELEMENT_STRING tmp;
						tmp.c = p[pos];
						if ((pos_next != p_len) && (p[pos_next] == '*')) {
							tmp.t_max = false;
							++pos;
						}
						else { tmp.t_min += 1; }
						rtn.push_back(tmp);
					}
					else {
						if ((pos_next != p_len) && (p[pos_next] == '*')) {
							last.t_max = false;
							++pos;
						}
						else { last.t_min += 1; }
					}
				}
			}
			else {
				cout << "T2: WTF??? =>" << p[pos] << endl;
			}
			++pos;
		}
		return rtn;
	}

	bool isMatch(string s, string p) {
		int s_len = s.length();
		int p_len = p.length();
		cout << "T1: " << p << endl;
		if (p_len == 0) { 
			if (s_len == 0) { return true; }
			else { return false; }
		}
		else { 
			if (checkQuality(p, p_len) == false) { return false; }
			vector<ELEMENT_STRING> vec = vectorize(p, p_len);
			///*cout << "VEC: ";
			//for (int i = 0; i < vec.size();++i) {
			//	cout << "\nchar:     " << vec[i].c
			//		<< "\nmin:      " << vec[i].t_min
			//		<< "\nmax(0/1): " << vec[i].t_max << endl;
			//}*/
			if ((vec.size() == 1) && (vec[0].c == '.') && (vec[0].t_min == 0)) { return true; }
			else {
			
			}
		}

		return false;
	}
};

int main() {

	string p, s;
	s = "dddabb";
	p = "a*a*bb*bb*b*bc*c*.*.*.b";
	p = ".*.*.*";
	bool ret = Solution().isMatch(s, p);

	
	cout << ret << endl;


	std::cout << "Wuzup world!" << std::endl;
	return 0;
}