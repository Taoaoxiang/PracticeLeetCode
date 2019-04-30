//Sort a linked list in O(n log n) time using constant space complexity.
//
//Example 1:
//
//Input: 4->2->1->3
//Output: 1->2->3->4
//
//Example 2:
//
//Input: -1->5->3->4->0
//Output: -1->0->3->4->5
//
//

//Runtime: 84 ms, faster than 21.99% of C++ online submissions for Sort List.
//Memory Usage : 29.7 MB, less than 5.02% of C++ online submissions for Sort List.

class Solution {
public:
	ListNode* merge(ListNode* h1, ListNode* h2) {
		ListNode* p0 = new ListNode(0), * p = p0;
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
		while (p1 != NULL && p1->next != NULL) {
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