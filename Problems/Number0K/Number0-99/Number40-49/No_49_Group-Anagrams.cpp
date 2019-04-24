//Given an array of strings, group anagrams together.
//
//Example:
//
//Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
//	Output :
//	[
//		["ate", "eat", "tea"],
//		["nat", "tan"],
//		["bat"]
//	]
//
//	   Note :
//
//		   All inputs will be in lowercase.
//		   The order of your output does not matter.
//


//Runtime: 56 ms, faster than 53.03% of C++ online submissions for Group Anagrams.
//Memory Usage : 18.9 MB, less than 86.66% of C++ online submissions for Group Anagrams.

// This is okay solution.
class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		if (strs.size() == 0) { return {}; }
		vector<vector<string>> rtn;
		map<string, vector<string>> hMap;
		map<string, vector<string>>::iterator it;
		for (int i = 0; i < strs.size(); ++i) {
			string sortedStr = strs[i];
			sort(sortedStr.begin(), sortedStr.end());
			it = hMap.find(sortedStr);
			if (it != hMap.end()) { hMap[sortedStr].push_back(strs[i]); }
			else { hMap[sortedStr] = { strs[i] }; }
		}
		for (it = hMap.begin();it != hMap.end();++it) {
			rtn.push_back(it->second);
		}
		return rtn;
	}
};