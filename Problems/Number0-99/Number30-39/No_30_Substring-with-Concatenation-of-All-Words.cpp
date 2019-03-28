//You are given a string, s, and a list of words, words, that are all of the same length.Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//Example 1:
//
//Input:
//s = "barfoothefoobarman",
//words = ["foo", "bar"]
//Output : [0, 9]
//	Explanation : Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
//	The output order does not matter, returning[9, 0] is fine too.
//
//	Example 2 :
//
//	Input :
//	s = "wordgoodgoodgoodbestword",
//	words = ["word", "good", "best", "word"]
//	Output : []
//


//Runtime: 348 ms, faster than 33.38% of C++ online submissions for Substring with Concatenation of All Words.
//Memory Usage : 37.4 MB, less than 31.10% of C++ online submissions for Substring with Concatenation of All Words.

// Man, this takes long time to pass the submission.
// I tried other ways, but LeetCode complains that too slow? While it was fine on my laptop. :)
class Solution {
public:
	bool recursiveWordSeek(string str, int wordLen, map<string, int> &wordFreq, vector<string>& wordUniq) {
		if (str.length() == 0) { return true; }
		map<string, int> hashMap;
		for (int i = 0; i < str.length(); i = i + wordLen) {
			string subStr = str.substr(i, wordLen);
			if (hashMap.find(subStr) != hashMap.end()) { ++hashMap[subStr]; }
			else { hashMap[subStr] = 1; }
		}
		for (int i = 0; i < wordUniq.size(); ++i) {
			if (hashMap.find(wordUniq[i]) != hashMap.end()) {
				if (wordFreq[wordUniq[i]] != hashMap[wordUniq[i]]) { return false; }
			}
			else { return false; }
		}
		return true;
	}

	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> rtn;
		if (words.size() == 0) { return rtn; }
		// All empty strings in the vector
		if (words[0].length() == 0) {
			for (int i = 0; i <= s.length(); ++i) { rtn.push_back(i); }
			return rtn;
		}
		int wordLen = words[0].length();
		int wordsSize = words.size();
		int wordsTotalLen = wordsSize * wordLen;
		int sLen = s.length();
		if (wordsTotalLen > sLen) { return rtn; }
		map<string, int> wordFreq;
		vector<string> wordUniq;
		for (int i = 0; i < wordsSize; i++) {
			if (wordFreq.find(words[i]) != wordFreq.end()) { ++wordFreq[words[i]]; }
			else {
				wordFreq[words[i]] = 1;
				wordUniq.push_back(words[i]);
			}
		}
		vector<int> vecAllPos;
		for (int i = 0; i < wordUniq.size(); ++i) {
			int iFound;
			iFound = s.find(wordUniq[i]);
			if (iFound == string::npos) { return rtn; }
			while (iFound != string::npos) {
				vecAllPos.push_back(iFound);
				iFound = s.find(wordUniq[i], iFound + 1);
			}
		}
		//cout << "T0: " << endl;
		// Sort the vector
		sort(vecAllPos.begin(), vecAllPos.end());
		// Remove duplicate
		int iRemoveDup = 0;
		int iDupTemp;
		while (iRemoveDup < vecAllPos.size()) {
			if (iRemoveDup == 0) {
				iDupTemp = vecAllPos[iRemoveDup];
				++iRemoveDup;
			}
			else {
				if (vecAllPos[iRemoveDup] == iDupTemp) { vecAllPos.erase(vecAllPos.begin() + iRemoveDup); }
				else {
					iDupTemp = vecAllPos[iRemoveDup];
					++iRemoveDup;
				}
			}
		}

		for (int i = 0; i < vecAllPos.size(); i++) {
			//cout << "T2: " << endl;
			if (vecAllPos[i] <= (sLen - wordsTotalLen)) {
				if (recursiveWordSeek(s.substr(vecAllPos[i], wordsTotalLen), wordLen, wordFreq, wordUniq) == true) {
					rtn.push_back(vecAllPos[i]);
				}
			}
			else { break; }
		}
		return rtn;
	}
};