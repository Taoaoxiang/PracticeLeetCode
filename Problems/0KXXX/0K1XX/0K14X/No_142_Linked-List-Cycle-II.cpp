//Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
//Note: Do not modify the linked list.
//
// 
//
//Example 1:
//
//Input: head = [3,2,0,-4], pos = 1
//Output: tail connects to node index 1
//Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//Example 2:
//
//Input: head = [1,2], pos = 0
//Output: tail connects to node index 0
//Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//Example 3:
//
//Input: head = [1], pos = -1
//Output: no cycle
//Explanation: There is no cycle in the linked list.
//
// 
//
//Follow up:
//Can you solve it without using extra space?


//Runtime: 12 ms, faster than 99.30% of C++ online submissions for Linked List Cycle II.
//Memory Usage : 9.7 MB, less than 65.20% of C++ online submissions for Linked List Cycle II.

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) { return NULL; }
		ListNode* pFast = head->next->next, * pSlow = head->next;
		while (pFast != pSlow) {
			if (pFast == NULL || pFast->next == NULL) { return NULL; }
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		pSlow = head;
		while (pSlow != pFast) {
			pSlow = pSlow->next;
			pFast = pFast->next;
		}
		return pSlow;
	}
};

//Runtime: 12 ms, faster than 99.30% of C++ online submissions for Linked List Cycle II.
//Memory Usage : 9.9 MB, less than 19.38% of C++ online submissions for Linked List Cycle II.

class Solution {
public:
	ListNode* detectCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) { return NULL; }
		ListNode* pFast = head->next->next, * pSlow = head->next;
		while (pFast != NULL) {
			if (pFast == NULL || pFast->next == NULL) { return NULL; }
			if (pSlow == pFast) {
				pSlow = head;
				while (pSlow != pFast) {
					pSlow = pSlow->next;
					pFast = pFast->next;
				}
				return pSlow;
			}
			else {
				pSlow = pSlow->next;
				pFast = pFast->next->next;
			}
		}
		return NULL;
	}
};

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