/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 * Explanation: 342 + 465 = 807.
 *
 */

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int tmp_sum = l1->val + l2->val;
		ListNode* r = new ListNode(tmp_sum % 10);
		ListNode* l3 = r;
		int rmd = tmp_sum / 10;
		l1 = l1->next;
		l2 = l2->next;
		while (l1 != NULL || l2 != NULL) {
			l3->next = new ListNode(rmd);
			l3 = l3->next;
			if (l1 != NULL) {
				l3->val += l1->val;
				l1 = l1->next;
			}
			if (l2 != NULL) {
				l3->val += l2->val;
				l2 = l2->next;
			}
			rmd = l3->val / 10;
			l3->val = l3->val % 10;
		}
		if (rmd > 0) {
			l3->next = new ListNode(rmd);
		}
		return r;
	}
};