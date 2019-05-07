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

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return {}; }
		if (beginWord == endWord) { return { {endWord} }; }
		unordered_map<string, unordered_set<string>> uStr;
		unordered_map<string, bool> uBool;
		vector<vector<string>> rtn;
		unordered_set<string> uSet(wordList.begin(), wordList.end());
		uSet.insert(beginWord);
		unordered_set<string>::iterator it;
		for (it = uSet.begin(); it != uSet.end(); ++it) {
			uStr[*it] = {};
			uBool[*it] = false;
			for (int i = 0; i < (*it).size(); ++i) {
				string s(*it);
				for (char c = 'a'; c <= 'z'; ++c) {
					s[i] = c;
					if (s != *it && uSet.find(s) != uSet.end()) { uStr[*it].insert(s); }
				}
			}
		}
		queue<vector<string>> qVec;
		qVec.push({ beginWord });
		while (!qVec.empty()) {
			//cout << "T2: .size()=>" << qVec.size() << endl;
			if (!rtn.empty()) { break; }
			queue<vector<string>> qVecTemp;
			unordered_set<string> uBTemp;
			while (!qVec.empty()) {
				vector<string> vTemp = qVec.front();
				qVec.pop();
				string sTemp = vTemp.back();
				for (it = uStr[sTemp].begin(); it != uStr[sTemp].end(); ++it) {
					if (uBool[*it] == false) {
						vTemp.push_back(*it);
						uBTemp.insert(*it);
						if (*it == endWord) { rtn.push_back(vTemp); }
						else { qVecTemp.push(vTemp); }
						vTemp.pop_back();
					}
				}
			}
			for (it = uBTemp.begin(); it != uBTemp.end(); ++it) { uBool[*it] = true; }
			qVec = qVecTemp;
		}

		//for (auto it = uPStr.begin(); it != uPStr.end(); ++it) {	cout << it->first << ",";}
		//cout << endl;

		return rtn;
	}
};


/////
////






int main() {
	vector<string> s1= { "aa","aaa","aaa","aaa", "aaa", "aaaa", "bb" };
	unordered_set<string> myset(s1.begin(),s1.end());
	string s = "";
	for (auto it = myset.begin(); it != myset.end(); ++it) {
		cout << *it << ", ";
	}
	cout << endl;



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}