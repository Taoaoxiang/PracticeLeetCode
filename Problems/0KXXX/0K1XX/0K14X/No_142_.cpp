

//Runtime: 20 ms, faster than 35.50% of C++ online submissions for Linked List Cycle II.
//Memory Usage : 12.2 MB, less than 5.29% of C++ online submissions for Linked List Cycle II.

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		unordered_set<ListNode*> uS;
		while (head != NULL) {
			if (uS.find(head) != uS.end()) { return head; }
			else { uS.insert(head); }
			head = head->next;
		}
		return head;
	}
};