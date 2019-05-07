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
	string ssEnd;
	int ssSize;
	unordered_map<string, bool> uMap;
	vector<vector<string>> rtn;
	struct StrNode
	{
		string val;
		vector<StrNode*> friends;
		StrNode(string s) : val(s) {}
	};
	
	void reS(string curWord, vector<string>& vec, vector<string>& wordList) {
		if (rtn.size() > 0 && (vec.size() >= rtn.front().size())) { return; }
		if (curWord == ssEnd) {
			vec.push_back(curWord);
			if (rtn.size() == 0 || (rtn.front().size() == vec.size())) { rtn.push_back(vec); }
			else if (rtn.front().size() > vec.size()) {
				rtn.clear();
				rtn.push_back(vec);
			}
			vec.pop_back();
			return;
		}
		for (int i = 0; i < ssSize; ++i) {
			for (char c = 'a'; c <= 'z'; ++c) {
				string s(curWord);
				s[i] = c;
				if (uMap.find(s) != uMap.end() && uMap[s] == false) {
					uMap[s] = true;
					reS(s, vec, wordList);
					uMap[s] = false;
				}
			
			}
		}
	}


	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return {}; }
		StrNode* sBegin = new StrNode(beginWord);
		ssEnd = endWord;
		ssSize = beginWord.size();
		vector<string> vec;
		unordered_set<string> uAll(wordList.begin(), wordList.end());
		
		for (int i = 0; i < wordList.size(); ++i) { uMap.insert({ wordList[i], false }); }
		reS(beginWord, vec, wordList);


		for (int i = 0; i < wordList.size(); ++i) {
			for (int i2 = 0; i2 < wordList[i].size(); ++i2) {
				for (char c = 'a'; c <= 'z'; ++c) {

					if (c != wordList[i][i2]) {
						string s = wordList[i];
						s[i2] = c;
						if (uAll.find(s) != uAll.end()) {
						
						
						}
					}
				
				}
			}
		}

		return {};
	}
};


/////
////



int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}