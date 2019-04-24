//Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//Example:
//
//Input: S = "ADOBECODEBANC", T = "ABC"
//	Output : "BANC"
//
//	Note :
//
//	If there is no such window in S that covers all characters in T, return the empty string "".
//	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//

//Runtime: 276 ms, faster than 5.07% of C++ online submissions for Minimum Window Substring.
//Memory Usage : 11.5 MB, less than 31.03% of C++ online submissions for Minimum Window Substring.

// My own solution, quite slow
// At least it's better the other "Time Limit Exceeded" solution, LOL
class Solution {
public:
	string minWindow(string s, string t) {
		if (s.size() == 0 || t.size() == 0) { return ""; }
		else if (s.size() < t.size()) { return ""; }
		vector<string> vec;
		map<char, int> mapT;
		for (int i = 0;i < t.size();++i) {
			if (mapT.find(t[i]) != mapT.end()) { ++mapT[t[i]]; }
			else { mapT[t[i]] = 1; }
		}
		map<char, vector<int>> mapVec;
		int iStart = s.size(), iEnd = 0;
		char cStart;
		for (map<char, int>::iterator it = mapT.begin(); it != mapT.end(); ++it) {
			int iFind = s.find(it->first);
			if (iFind < iStart) {
				iStart = iFind;
				cStart = it->first;
			}
			while (iFind != string::npos) {
				mapVec[it->first].push_back(iFind);
				iFind = s.find(it->first, iFind + 1);
			}
			if (it->second <= mapVec[it->first].size()) {
				if (mapVec[it->first][(it->second) - 1] > iEnd) { iEnd = mapVec[it->first][(it->second) - 1]; }
			}
			else { return ""; }
		}
		int iStartMin = iStart, iEndMin = iEnd;
		while (true) {
			//cout << "iStart=>" << iStart << ", iEnd=>" << iEnd << ", Char=>" << cStart << endl;
			mapVec[cStart].erase(mapVec[cStart].begin());
			if (mapT[cStart] <= mapVec[cStart].size()) {
				if (mapVec[cStart][mapT[cStart] - 1] > iEnd) { iEnd = mapVec[cStart][mapT[cStart] - 1]; }
			}
			else { break; }
			iStart = s.size();
			for (auto it = mapVec.begin(); it != mapVec.end(); ++it) {
				if (iStart > it->second[0]) {
					iStart = it->second[0];
					cStart = it->first;
				}
			}
			if (iEnd - iStart + 1 < iEndMin - iStartMin + 1) {
				iStartMin = iStart;
				iEndMin = iEnd;
			}
		}
		return s.substr(iStartMin, iEndMin - iStartMin + 1);
	}
};