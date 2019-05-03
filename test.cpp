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


/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* next;
	Node* random;

	Node() {}

	Node(int _val, Node* _next, Node* _random) {
		val = _val;
		next = _next;
		random = _random;
	}
};
*/
class Solution {
public:
	Node* copyRandomList(Node* head) {
		if (head == NULL) { return NULL; }
		Node* p = head;
		unordered_map<Node*, Node*> uAll;
		uAll[head] = new Node(head->val, NULL, NULL);
		while (p != NULL) {
			if (p->next != NULL) {
				if (uAll.find(p->next) == uAll.end()) {
					uAll[p->next] = new Node(p->next->val, NULL, NULL);
				}
				uAll[p]->next = uAll[p->next];
			}
			if (p->random != NULL) {
				if (uAll.find(p->random) == uAll.end()) {
					uAll[p->random] = new Node(p->random->val, NULL, NULL);
				}
				uAll[p]->random = uAll[p->random];
			}		
			p = p->next;
		}
		return uAll[head];
	}
};



int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}