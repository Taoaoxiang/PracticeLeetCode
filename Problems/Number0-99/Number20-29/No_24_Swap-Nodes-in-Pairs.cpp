//Given a linked list, swap every two adjacent nodes and return its head.
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//
//
//Example:
//
//Given 1->2->3->4, you should return the list as 2->1->4->3.
//

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Swap Nodes in Pairs.
//Memory Usage : 8.6 MB, less than 100.00% of C++ online submissions for Swap Nodes in Pairs.
// WOW

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode *p = head;
		vector<ListNode*> vecNodes;
		while (p != NULL) {
			if (p->next == NULL) {
				vecNodes.push_back(p);
				p = NULL;
			}
			else {
				vecNodes.push_back(p->next);
				vecNodes.push_back(p);
				if (p->next->next == NULL) { p = NULL; }
				else { p = p->next->next; }
			}
		}
		for (int i = 0;i != vecNodes.size();++i) {
			if (i + 1 == vecNodes.size()) { vecNodes[i]->next = NULL; }
			else { vecNodes[i]->next = vecNodes[i + 1]; }
		}
		return vecNodes[0];
	}
};