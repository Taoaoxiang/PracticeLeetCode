//Given a linked list, determine if it has a cycle in it.
//
//To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.
//
// 
//
//Example 1:
//
//Input: head = [3,2,0,-4], pos = 1
//Output: true
//Explanation: There is a cycle in the linked list, where tail connects to the second node.
//
//Example 2:
//
//Input: head = [1,2], pos = 0

//Runtime: 12 ms, faster than 99.32% of C++ online submissions for Linked List Cycle.
//Memory Usage : 9.9 MB, less than 14.53% of C++ online submissions for Linked List Cycle.

class Solution {
public:
	bool hasCycle(ListNode* head) {
		if (head == NULL || head->next == NULL) { return false; }
		ListNode* p = head;
		ListNode* pF = head->next;
		while (p != pF) {
			if (pF == NULL || pF->next == NULL) { return false; }
			p = p->next;
			pF = pF->next->next;
		}
		return true;
	}
};

//Output: true
//Explanation: There is a cycle in the linked list, where tail connects to the first node.
//
//Example 3:
//
//Input: head = [1], pos = -1
//Output: false
//Explanation: There is no cycle in the linked list.
//
// 
//
//Follow up:
//
//Can you solve it using O(1) (i.e. constant) memory?


//Runtime: 20 ms, faster than 29.89% of C++ online submissions for Linked List Cycle.
//Memory Usage : 12 MB, less than 8.68% of C++ online submissions for Linked List Cycle.
class Solution {
public:
	bool hasCycle(ListNode* head) {
		unordered_set<ListNode*> sL;
		while (head != NULL) {
			if (sL.find(head) == sL.end()) {
				sL.insert(head);
				head = head->next;
			}
			else { return true; }
		}
		return false;
	}
};

//Runtime: 116 ms, faster than 5.36% of C++ online submissions for Linked List Cycle.
//Memory Usage : 10.7 MB, less than 13.77% of C++ online submissions for Linked List Cycle.

class Solution {
public:
	bool hasCycle(ListNode* head) {
		vector<ListNode*> vecAll;
		ListNode* p = head;
		while (p != NULL) {
			if (find(vecAll.begin(), vecAll.end(), p) == vecAll.end()) {
				vecAll.push_back(p);
				p = p->next;
			}
			else { return true; }
		}
		return false;
	}
};