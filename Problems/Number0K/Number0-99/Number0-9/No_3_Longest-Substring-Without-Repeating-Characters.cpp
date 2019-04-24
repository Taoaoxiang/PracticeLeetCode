//Given a string, find the length of the longest substring without repeating characters.
//
//Example 1:
//
//Input: "abcabcbb"
//	Output : 3
//	Explanation : The answer is "abc", with the length of 3.

// Oliver:
// :)
// I know my solution is super slow comparing to other people's 
// But you can at least know what is the longest substring

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int i_l = 1;
		int i_rtn = 0;
		size_t i_len = s.size();
		string s_s;
		size_t found;

		for (size_t i = 0; i != i_len;++i) {
			for (size_t i2 = i; i2 != i_len;++i2) {
				if (i == i2) {
					if (i != i_len - 1) {
						i_l = i2 - i + 1;
						s_s = s.substr(i, i_l);
						//std::cout << "T1: " << s_s << " " << i_l << std::endl;
					}
					else {
						if (i_rtn < i_l) { i_rtn = i_l; }
						break;
					}
				}
				else {
					found = s_s.find(s[i2]);
					if (found == std::string::npos) {
						i_l = i2 - i + 1;
						s_s = s.substr(i, i_l);
						//std::cout << "T2: " << s_s << " " << i_l << std::endl;
						if (i2 == i_len - 1) {
							if (i_rtn < i_l) { i_rtn = i_l; }
							break;
						}
					}
					else {
						if (i_rtn < i_l) { i_rtn = i_l; }
						break;
					}
				}
			}
		}
		return i_rtn;
	}
};