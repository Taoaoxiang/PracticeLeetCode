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

/*
// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};
*/
class Solution {
public:
	Node* cloneGraph(Node* node) {

	}
};

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) { return NULL; }


		unordered_set<ListNode*> uS;
		while (head != NULL) {
			if (uS.find(head) != uS.end()) { return head; }
			else { uS.insert(head); }
			head = head->next;
		}
		return head;
	}
};




int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}