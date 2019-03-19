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
		bool limited = true;
	};

	vector<ELEMENT_STRING> vectorize(string &p, int p_len) {
		vector<ELEMENT_STRING> rtn;
		int pos_next;
		int pos = 0;
		while (pos != p_len) {
			pos_next = pos + 1;
			if ((p[pos] >= 'a' && p[pos] <= 'z') || (p[pos] == '.')) {
				ELEMENT_STRING tmp;
				tmp.c = p[pos];
				if ((pos_next != p_len) && (p[pos_next] == '*')) {
					tmp.limited = false;
					++pos;
				}
				rtn.push_back(tmp);
			}
			else { cout << "T2: WTF??? =>" << p[pos] << endl; }
			++pos;
		}
		return rtn;
	}

	bool compare(string &s, int s_len, int s_pos, vector<ELEMENT_STRING> &v, int v_len, int v_pos) {
		//string st="";
		//for (int i = 0;i < v_pos;++i) { st += v[i].c; }
		//cout << "T1: " << s.substr(0, s_pos)
		//	<< "\nT2: =>" << st << endl;
		if ((s_pos == s_len) && (v_pos == v_len)) { return true; }
		else if (v_pos == v_len) { return false; }
		if (s_pos == s_len) {
			if (v[v_pos].limited == false) { return compare(s, s_len, s_pos, v, v_len, (v_pos + 1)); }
			else { return false; }
		}
		else {
			if (s[s_pos] == v[v_pos].c || v[v_pos].c == '.') {
				if (v[v_pos].limited == true) { return compare(s, s_len, (s_pos+1), v,v_len, (v_pos+1)); }
				else {
					return (compare(s, s_len, s_pos, v,v_len, (v_pos + 1))
						|| compare(s, s_len, (s_pos + 1), v, v_len,v_pos)
						|| compare(s, s_len, (s_pos + 1), v, v_len,(v_pos+1)));
				}
			}
			else {
				if (v[v_pos].limited == true) { return false; }
				else { return compare(s,s_len, s_pos, v,v_len, (v_pos+1)); }
			}
		}
	}


	bool isMatch(string s, string p) {
		int s_len = s.length();
		int p_len = p.length();
		//cout << "T1: " << p << endl;
		if (p_len == 0) { 
			if (s_len == 0) { return true; }
			else { return false; }
		}
		else { 
			if (checkQuality(p, p_len) == false) { return false; }
			vector<ELEMENT_STRING> vec = vectorize(p, p_len);
			//cout << "VEC: ";
			//for (int i = 0; i < vec.size();++i) {
			//	cout << "\nchar:     " << vec[i].c
			//		<< "\nLim:      " << vec[i].limited
			//		<< "\nSize:     " << vec.size()
			//		<< endl;
			//}
			return compare(s, s_len, 0, vec, vec.size(), 0);
		}
		return false;
	}
};

int main() {

	string p, s;
	s = "mississippi";
	s = "acaabbaccbbacaabbbb";
	//s = "acaab";
	//s = "a";
	s = "bbbba";
	p = ".*a*a";


		

	//p = "mis*is*p*.";
	//p = ".*.*.*";
	bool ret = Solution().isMatch(s, p);

	
	cout << ret << endl;


	std::cout << "Wuzup world!" << std::endl;
	return 0;
}