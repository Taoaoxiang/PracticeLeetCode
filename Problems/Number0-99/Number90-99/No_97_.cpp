//Runtime: 1868 ms, faster than 5.45% of C++ online submissions for Interleaving String.
//Memory Usage : 8.1 MB, less than 97.47% of C++ online submissions for Interleaving String.

// This needs to be improved
class Solution {
public:
	bool reSea(string& s1, int pos1, string& s2, int pos2, string& s3, int pos3) {
		if (pos3 >= s3.size()) { return true; }
		if (s1[pos1] == s2[pos2]) {
			if (s3[pos3] == s1[pos1]) { return reSea(s1, pos1 + 1, s2, pos2, s3, pos3 + 1) || reSea(s1, pos1, s2, pos2 + 1, s3, pos3 + 1); }
			else { return false; }
		}
		else {
			if (s3[pos3] == s1[pos1]) { return reSea(s1, pos1 + 1, s2, pos2, s3, pos3 + 1); }
			else if (s3[pos3] == s2[pos2]) { return reSea(s1, pos1, s2, pos2 + 1, s3, pos3 + 1); }
			else { return false; }
		}

	}
	bool isInterleave(string s1, string s2, string s3) {
		if (s1.size() + s2.size() != s3.size()) { return false; }
		if (s3.size() == 0) { return true; }
		return reSea(s1, 0, s2, 0, s3, 0);
	}
};