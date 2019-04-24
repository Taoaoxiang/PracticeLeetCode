//Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//You should preserve the original relative order of the nodes in each of the two partitions.
//
//Example:
//
//Input: head = 1->4->3->2->5->2, x = 3
//	Output : 1->2->2->4->3->5
//
//

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

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Partition List.
//Memory Usage : 8.7 MB, less than 52.97% of C++ online submissions for Partition List.

class Solution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode *pSHead = NULL, *pS = NULL, *pL = NULL, *pLHead = NULL, *p = head;
		while (p != NULL) {
			if (p->val < x) {
				if (pSHead == NULL) { pSHead = p; }
				else { pS->next = p; }
				pS = p;
			}
			else {
				if (pLHead == NULL) { pLHead = p; }
				else { pL->next = p; }
				pL = p;
			}
			p = p->next;
		}
		if (pSHead == NULL && pLHead == NULL) { return NULL; }
		else if (pSHead != NULL && pLHead == NULL) { return pSHead; }
		else if (pSHead == NULL && pLHead != NULL) { return pLHead; }
		else {
			pL->next = NULL;
			pS->next = pLHead;
			return pSHead;
		}
	}
};