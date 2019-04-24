//A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//'A' -> 1
//'B' -> 2
//...
//'Z' -> 26
//
//Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
//Example 1:
//
//Input: "12"
//Output: 2
//Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//Example 2:
//
//Input: "226"
//Output: 3
//Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//
//

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Decode Ways.
//Memory Usage : 8.2 MB, less than 94.57% of C++ online submissions for Decode Ways.

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0) { return 0; }
		int p = 1, pp = 0;
		for (int i = 0; i < s.size(); ++i) {
			int cur = 0;
			if (s[i] != '0') { cur = p; }
			if (i > 0 && (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] < '7'))) {
				cur += pp;
			}
			pp = p;
			p = cur;
		}
		return p;
	}
};

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Decode Ways.
//Memory Usage : 8.5 MB, less than 26.57% of C++ online submissions for Decode Ways.

class Solution {
public:
	int numDecodings(string s) {
		if (s.size() == 0) { return 0; }
		vector<int> vAll(s.size() + 1, 0);
		for (int i = 0; i < vAll.size(); ++i) {
			if (i == 0) { vAll[i] = 1; }
			else {
				int pos = i - 1;
				int prePos = i - 2;
				if (s[pos] != '0') { vAll[i] = vAll[pos]; }
				if (prePos >= 0 && (s[prePos] == '1' || (s[prePos] == '2' && s[pos] < '7'))) {
					vAll[i] += vAll[prePos];
				}
			}
		}
		return vAll[s.size()];

	}
};