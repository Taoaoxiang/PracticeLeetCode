//Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
//
//    Only one letter can be changed at a time.
//    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//Note:
//
//    Return 0 if there is no such transformation sequence.
//    All words have the same length.
//    All words contain only lowercase alphabetic characters.
//    You may assume no duplicates in the word list.
//    You may assume beginWord and endWord are non-empty and are not the same.
//
//Example 1:
//
//Input:
//beginWord = "hit",
//endWord = "cog",
//wordList = ["hot","dot","dog","lot","log","cog"]
//
//Output: 5
//
//Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//
//Example 2:
//
//Input:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//Output: 0
//
//Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//

//Runtime: 76 ms, faster than 84.49% of C++ online submissions for Word Ladder.
//Memory Usage : 14.2 MB, less than 39.36% of C++ online submissions for Word Ladder.

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		unordered_set<string> uSet(wordList.begin(), wordList.end());
		uSet.erase(beginWord);
		queue<string> qVec;
		qVec.push(beginWord);
		int rtn = 0;
		while (!qVec.empty()) {
			++rtn;
			queue<string> qVecTemp;
			while (!qVec.empty()) {
				string s0(qVec.front());
				qVec.pop();
				if (s0 == endWord) { return rtn; }
				for (int i = 0; i < s0.size(); ++i) {
					string s1(s0);
					for (char c = 'a'; c <= 'z'; ++c) {
						s1[i] = c;
						if (uSet.find(s1) != uSet.end()) {
							qVecTemp.push(s1);
							uSet.erase(s1);
						}
					}
				}
			}
			qVec = qVecTemp;
		}

		return 0;
	}
};

//Runtime: 212 ms, faster than 47.27% of C++ online submissions for Word Ladder.
//Memory Usage : 28.7 MB, less than 7.10% of C++ online submissions for Word Ladder.

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return 0; }
		if (beginWord == endWord) { return 1; }
		unordered_map<string, unordered_set<string>> uStr;
		unordered_map<string, bool> uBool;
		int rtn = 1;
		unordered_set<string> uSet(wordList.begin(), wordList.end());
		uSet.insert(beginWord);
		unordered_set<string>::iterator it;
		for (it = uSet.begin(); it != uSet.end(); ++it) {
			uStr[*it] = {};
			for (int i = 0; i < (*it).size(); ++i) {
				string s(*it);
				for (char c = 'a'; c <= 'z'; ++c) {
					s[i] = c;
					if (s != *it && uSet.find(s) != uSet.end()) { uStr[*it].insert(s); }
				}
			}
		}
		queue<string> qVec;
		qVec.push(beginWord);
		uSet.erase(beginWord);
		while (!qVec.empty()) {
			//cout << "T2: .size()=>" << qVec.size() << endl;
			++rtn;
			queue<string> qVecTemp;
			while (!qVec.empty()) {
				string sTemp = qVec.front();
				qVec.pop();
				for (it = uStr[sTemp].begin(); it != uStr[sTemp].end(); ++it) {
					if (uSet.find(*it) != uSet.end()) {
						if (*it == endWord) { return rtn; }
						qVecTemp.push(*it);
						uSet.erase(*it);
					}
				}
			}
			qVec = qVecTemp;
		}

		return 0;
	}
};


//Runtime: 408 ms, faster than 40.42% of C++ online submissions for Word Ladder.
//Memory Usage : 169.9 MB, less than 5.04% of C++ online submissions for Word Ladder.

class Solution {
public:
	int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return 0; }
		if (beginWord == endWord) { return 1; }
		unordered_map<string, unordered_set<string>> uStr;
		unordered_map<string, bool> uBool;
		int rtn = 0;
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
			queue<vector<string>> qVecTemp;
			unordered_set<string> uBTemp;
			while (!qVec.empty()) {
				vector<string> vTemp = qVec.front();
				qVec.pop();
				string sTemp = vTemp.back();
				for (it = uStr[sTemp].begin(); it != uStr[sTemp].end(); ++it) {
					if (uBool[*it] == false) {
						vTemp.push_back(*it);
						if (*it == endWord) { return vTemp.size(); }
						uBTemp.insert(*it);
						qVecTemp.push(vTemp);
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