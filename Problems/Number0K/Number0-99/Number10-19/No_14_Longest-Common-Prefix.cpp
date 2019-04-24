//Write a function to find the longest common prefix string amongst an array of strings.
//
//If there is no common prefix, return an empty string "".
//
//Example 1:
//
//Input: ["flower", "flow", "flight"]
//	Output : "fl"
//
//	Example 2 :
//
//	Input : ["dog", "racecar", "car"]
//	Output : ""
//	Explanation : There is no common prefix among the input strings.
//

// This solution works, not fast tho. :)
class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string rtn;
		if (strs.size() == 0) { return ""; }
		else {
			int min_len = (*min_element(strs.begin(), strs.end())).length();
			for (int i = 0; i != min_len;++i) {
				for (auto const& s : strs) {
					if (s[i] != strs[0][i]) { return rtn; }
				}
				rtn += strs[0][i];
			}
		}
		return rtn;
	}
};