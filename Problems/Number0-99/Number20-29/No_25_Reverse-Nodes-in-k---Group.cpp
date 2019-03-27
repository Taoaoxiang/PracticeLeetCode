//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list.If the number of nodes is not a multiple of k then left - out nodes in the end should remain as it is.
//
//Example:
//
//Given this linked list : 1->2->3->4->5
//
//For k = 2, you should return : 2->1->4->3->5
//
//For k = 3, you should return : 3->2->1->4->5
//
//Note :
//
//	Only constant extra memory is allowed.
//	You may not alter the values in the list's nodes, only nodes itself may be changed.
//
//


//Runtime: 20 ms, faster than 100.00% of C++ online submissions for Reverse Nodes in k - Group.
//Memory Usage : 10.3 MB, less than 15.83% of C++ online submissions for Reverse Nodes in k - Group.

// This is the number version, iterator version should be better??? :)
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (head == NULL || head->next == NULL) { return head; }
		else if (k == 1) { return head; }
		ListNode *p = head;
		vector<ListNode*> vecNodes;
		while (p != NULL) {
			vecNodes.push_back(p);
			p = p->next;
		}
		if (vecNodes.size() < k) { return head; }
		else {
			int i_remainder = vecNodes.size() % k;
			int i_quotient = vecNodes.size() / k;
			ListNode* tmpFromLToR = NULL;
			for (int i = 0; i < i_quotient;++i) {
				int iL = i * k;
				int iR = (i + 1)*k - 1;
				while (iL < iR) {
					tmpFromLToR = vecNodes[iL];
					vecNodes[iL] = vecNodes[iR];
					vecNodes[iR] = tmpFromLToR;
					++iL;
					--iR;
				}
			}
			for (int i = 0; i < vecNodes.size();++i) {
				if (i + 1 == vecNodes.size()) { vecNodes[i]->next = NULL; }
				else { vecNodes[i]->next = vecNodes[i + 1]; }
			}
		}
		return vecNodes[0];
	}
};