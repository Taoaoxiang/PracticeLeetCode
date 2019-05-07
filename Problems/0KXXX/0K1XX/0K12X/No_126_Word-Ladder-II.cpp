//Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//    Only one letter can be changed at a time
//    Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//Note:
//
//    Return an empty list if there is no such transformation sequence.
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
//Output:
//[
//  ["hit","hot","dot","dog","cog"],
//  ["hit","hot","lot","log","cog"]
//]
//
//Example 2:
//
//Input:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log"]
//
//Output: []
//
//Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//

//Runtime: 456 ms, faster than 51.65% of C++ online submissions for Word Ladder II.
//Memory Usage : 172.8 MB, less than 27.87% of C++ online submissions for Word Ladder II.

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

//Runtime: 396 ms, faster than 55.36% of C++ online submissions for Word Ladder II.
//Memory Usage : 173.1 MB, less than 27.87% of C++ online submissions for Word Ladder II.

class Solution {
public:
	// uStr:	store all uniq str and its neighbors
	unordered_map<string, unordered_set<string>> uStr; 
	// uBool:	check the str visited or not in the previous while loop 
	unordered_map<string, bool> uBool;
	vector<vector<string>> rtn;

	vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
		if (find(wordList.begin(), wordList.end(), endWord) == wordList.end()) { return {}; }
		if (beginWord == endWord) { return { {endWord} }; }
		
		// uSet:	get all the strs
		//			sometimes the wordList contains beginWord, sometimes not
		unordered_set<string> uSet(wordList.begin(), wordList.end());
		uSet.insert(beginWord);

		// Get all the strings and its neighbors
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
			// If we got the results in the last loop
			// Then we need to stop here
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
			// Mark all the visited strings in the current loop
			for (it = uBTemp.begin(); it != uBTemp.end(); ++it) { uBool[*it] = true; }
			qVec = qVecTemp;
		}

		return rtn;
	}
};