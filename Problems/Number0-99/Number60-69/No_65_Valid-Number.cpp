//Validate if a given string can be interpreted as a decimal number.
//
//Some examples :
//"0" = > true
//" 0.1 " = > true
//"abc" = > false
//"1 a" = > false
//"2e10" = > true
//" -90e3   " = > true
//" 1e" = > false
//"e3" = > false
//" 6e-1" = > true
//" 99e2.5 " = > false
//"53.5e93" = > true
//" --6 " = > false
//"-+3" = > false
//"95a54e53" = > false
//
//Note: It is intended for the problem statement to be ambiguous.You should gather all requirements up front before implementing one.However, here is a list of characters that can be in a valid decimal number :
//
//Numbers 0 - 9
//Exponent - "e"
//Positive / negative sign - "+" / "-"
//Decimal point - "."
//
//Of course, the context of these characters also matters in the input.

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Valid Number.
//Memory Usage : 8.2 MB, less than 100.00% of C++ online submissions for Valid Number.

class Solution {
public:
	pair<int, int> checkExp(string str) {
		pair<int, int> rtn = { 0,0 };
		int pos = str.find('e');
		while (pos != string::npos) {
			++rtn.first;
			rtn.second = pos;
			str.erase(str.begin() + pos);
			pos = str.find('e');
		}
		return rtn;
	}

	bool checkSign(string& str) {
		int sign = 0;
		while (str.front() == '-' || str.front() == '+') {
			++sign;
			str.erase(str.begin());
		}
		if (sign > 1) { return false; }
		else { return true; }
	}

	void removeDot(string &str) {
		int pos = str.find('.');
		if (pos != string::npos) { str.erase(str.begin() + pos); }
	}

	bool isNumber(string s) {
		string str(s);
		while (str.back() == ' ') { str.pop_back(); }
		while (str.front() == ' ') { str.erase(str.begin()); }
		pair<int, int> ePair = checkExp(str);
		if (ePair.first > 1) { return false; }
		else if (ePair.first == 1) {
			if ((ePair.second == str.size() - 1) || (ePair.second == 0)) { return false; }
			string sBase = str.substr(0, ePair.second);
			string sExp = str.substr(ePair.second + 1);
			if ((checkSign(sBase) == false) || (checkSign(sExp) == false)) { return false; }
			removeDot(sBase);
			if ((sBase.size() == 0) || (sExp.size() == 0)) { return false; }
			for (int i = 0; i < sBase.size(); ++i) { if (sBase[i] > '9' || sBase[i] < '0') { return false; } }
			for (int i = 0; i < sExp.size(); ++i) { if (sExp[i] > '9' || sExp[i] < '0') { return false; } }
		}
		else if (ePair.first == 0) {
			if (checkSign(str) == false) { return false; }
			removeDot(str);
			if (str.size() == 0) { return false; }
			for (int i = 0; i < str.size(); ++i) { if (str[i] > '9' || str[i] < '0') { return false; } }
		}

		return true;
	}
};
