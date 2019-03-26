//Given a linked list, remove the n - th node from the end of list and return its head.
//
//Example:
//
//Given linked list : 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//
//Note :
//
//	Given n will always be valid.
//
//	Follow up :
//
//Could you do this in one pass ?


//Runtime: 8 ms, faster than 99.69% of C++ online submissions for Remove Nth Node From End of List.
//Memory Usage : 8.5 MB, less than 100.00% of C++ online submissions for Remove Nth Node From End of List

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (head == NULL) { return NULL; }
		else if (head->next == NULL) {
			if (n == 0) { return head; }
			else { return NULL; }
		}

		ListNode* rtn = NULL;
		ListNode* p = head;
		vector<ListNode*> vecP;
		while (p != NULL) {
			vecP.push_back(p);
			p = p->next;
		}


		int iLeft = vecP.size() - n - 1;
		int iTBR = vecP.size() - n;
		int iRight = vecP.size() - n + 1;

		if (iTBR == 0) {
			rtn = vecP[iRight];
			return rtn;
		}

		if (iTBR == vecP.size() - 1) {
			vecP[iLeft]->next = NULL;
			rtn = head;
			return rtn;
		}

		vecP[iLeft]->next = vecP[iRight];
		rtn = head;

		return rtn;
	}
};