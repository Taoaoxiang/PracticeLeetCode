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
		ListNode* pFast = head->next->next, *pSlow = head->next;
		while (pFast != NULL) {
			if (pFast == NULL || pFast->next == NULL) { return NULL; }
			if (pSlow == pFast) { 
				pSlow = head;
				while (pSlow != pFast) {
					pSlow = pSlow->next;
					pFast = pFast->next;
				}
				return pSlow; }
			else {
				pSlow = pSlow->next;
				pFast = pFast->next->next;
			}
		}
		return NULL;
	}
};




int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}