//Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//Example:
//
//Input: "25525511135"
//	Output : ["255.255.11.135", "255.255.111.35"]
//
//

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Restore IP Addresses.
//Memory Usage : 9.7 MB, less than 8.87% of C++ online submissions for Restore IP Addresses.

class Solution {
public:
	void reSearch(int dotNum, int poDotPos, int pos, string s, vector<string>& rtn) {
		if (pos >= s.size()) { return; }
		if (dotNum < 3) {
			if (s[poDotPos] == '0' && (pos - poDotPos + 1) > 1) { return; }
			else if (((pos - poDotPos + 1) <= 3) && stoi(s.substr(poDotPos, pos - poDotPos + 1)) <= 255) {
				reSearch(dotNum, poDotPos, pos + 1, s, rtn);
				s.insert(s.begin() + pos + 1, '.');
				reSearch(dotNum + 1, pos + 2, pos + 2, s, rtn);
			}
		}
		else if (dotNum == 3){
			if (s[poDotPos] == '0' && (s.size() - poDotPos) > 1) { return; }
			else if (((s.size() - poDotPos) <= 3) && stoi(s.substr(poDotPos, s.size() - poDotPos)) <= 255) { rtn.push_back(s); }
		}
		return;
	}

	vector<string> restoreIpAddresses(string s) {
		vector<string> rtn;
		if (s.size() < 4) { return {}; }
		reSearch(0, 0, 0, s, rtn);
		return rtn;
	}
};