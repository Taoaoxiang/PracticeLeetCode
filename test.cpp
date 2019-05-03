#include "include_LeetCode.h"


//
//class Solution {
//public:
//	int candy(vector<int>& ratings) {
//		int nums = ratings.size();
//		if ( nums == 0) { return 0; }
//		else if (nums == 1) { return 1; }
//		else if (nums == 2) {
//			if (ratings[0] == ratings[1]) { return 2; }
//			else { return 3; }
//		}
//		else {
//			int rtn = 0;
//
//
//
//			sort(ratings.begin(), ratings.end());
//			int iLast = INT_MIN;
//			int iCandy = 0;
//			for (int i = 0; i < nums; ++i) {
//				if (ratings[i] > iLast) {
//					++iCandy;
//					iLast = ratings[i];
//				}
//				else {
//					if (iCandy - 1 > 0) { --iCandy; }
//				}
//				rtn += iCandy;
//			}
//			return rtn;
//		}
//	}
//};


class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {

	}
};

class Solution {
public:
	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return {}; }

		return {};
	}
};


class Solution {
public:
	int rtn = 0;

	int minCut(string s) {
		int sSize = s.size();
		if (sSize == 0) { return -1; }
		else if (sSize == 1) { return 0; }
		
		res(0, s, rtn);
		return rtn;
	}
};



int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}