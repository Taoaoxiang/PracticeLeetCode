//Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//Example 1:
//
//Input: 1->1->2
//	Output : 1->2
//
//	Example 2 :
//
//	Input : 1->1->2->3->3
//	Output : 1->2->3
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

//Runtime: 12 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List.
//Memory Usage : 9.1 MB, less than 80.40% of C++ online submissions for Remove Duplicates from Sorted List.

class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode *p = head;
		while (p->next != NULL) {
			if (p->val == p->next->val) { p->next = p->next->next; }
			else { p = p->next; }
		}

		return head;
	}
};