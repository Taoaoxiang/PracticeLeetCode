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
	ListNode* merge(ListNode* h1, ListNode* h2) {
		ListNode* p0 = new ListNode(0), *p = p0;
		while (h1 != NULL && h2 != NULL) {
			if (h1->val < h2->val) {
				p->next = h1;
				h1 = h1->next;
			}
			else {
				p->next = h2;
				h2 = h2->next;
			}
			p = p->next;
		}
		if (h1 != NULL) { p->next = h1; }
		if (h2 != NULL) { p->next = h2; }
		return p0->next;
	}

	ListNode* sortList(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		//cout << "T0: " << head->val << endl;
		ListNode* p0 = new ListNode(0);
		p0->next = head;
		ListNode* p1 = head;
		while (p1!=NULL && p1->next != NULL) {
			p0 = p0->next;
			p1 = p1->next->next;
		}
		ListNode* p2 = p0->next;
		p0->next = NULL;
		ListNode* l0 = sortList(head);
		ListNode* l1 = sortList(p2);
		return merge(l0, l1);
	}
};




int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}