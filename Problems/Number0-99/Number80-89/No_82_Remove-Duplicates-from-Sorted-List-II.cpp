//Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//Example 1:
//
//Input: 1->2->3->3->4->4->5
//	Output : 1->2->5
//
//	Example 2 :
//
//	Input : 1->1->1->2->3
//	Output : 2->3
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

//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Remove Duplicates from Sorted List II.
//Memory Usage: 9.1 MB, less than 45.15% of C++ online submissions for Remove Duplicates from Sorted List II.

// This method is fastest of all, yay! :)
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode *p = head, *pPre = NULL;
		bool i = false;
		while (p->next != NULL) {
			if (p->val == p->next->val) {
				i = true;
				p->next = p->next->next;
			}
			else {
				if (i == false) {
					if (pPre == NULL) { head = p; }
					else { pPre->next = p; }
					pPre = p;
				}
				else { i = false; }
				p = p->next;
			}
		}
		if (pPre != NULL) {
			if (i == false) { pPre->next = p; }
			else { pPre->next = NULL; }
		}
		else {
			if (i == false) { return p; }
			else { return NULL; }
		}

		return head;
	}
};

//Runtime: 16 ms, faster than 21.55% of C++ online submissions for Remove Duplicates from Sorted List II.
//Memory Usage : 9 MB, less than 77.19% of C++ online submissions for Remove Duplicates from Sorted List II.

// Slowest of pointers
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode* p = head, *pNext = head->next, *pHead = NULL, *pPre = NULL;
		int i = 0;
		while (pNext != NULL) {
			if (p->val == pNext->val) {
				i = 1;
				pNext = pNext->next;
			}
			else {
				if (i == 0) {
					if (pPre == NULL) { pHead = p; }
					else { pPre->next = p; }
					pPre = p;
					p = p->next;
				}
				else {
					p = pNext;
					i = 0;
				}
				pNext = p->next;
			}
		}
		if (pPre != NULL) {
			if (i == 0) { pPre->next = p; }
			else { pPre->next = NULL; }
		}
		else {
			if (i == 0) { pHead = p; }
		}

		return pHead;
	}
};

//Runtime: 12 ms, faster than 58.44% of C++ online submissions for Remove Duplicates from Sorted List II.
//Memory Usage : 9.2 MB, less than 20.87% of C++ online submissions for Remove Duplicates from Sorted List II.

// Method 2: fastest of vector
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL) { return head; }
		ListNode* p = head, *pNext = head->next;
		vector<ListNode*> vecAll;
		int i = 0;
		while (pNext != NULL) {
			if (p->val == pNext->val) {
				i = 1;
				pNext = pNext->next;
			}
			else {
				if (i == 0) {
					vecAll.push_back(p);
					p = p->next;
					pNext = p->next;
				}
				else {
					p = pNext;
					pNext = p->next;
					i = 0;
				}
			}
		}
		if (i == 0) { vecAll.push_back(p); }

		if (vecAll.size() == 0) { return NULL; }
		else {
			for (int i = 0; i < vecAll.size();++i) {
				if (i == vecAll.size() - 1) { vecAll[i]->next = NULL; }
				else { vecAll[i]->next = vecAll[i + 1]; }
			}
			return vecAll[0];
		}
	}
};


//Runtime: 20 ms, faster than 7.46% of C++ online submissions for Remove Duplicates from Sorted List II.
//Memory Usage : 9.6 MB, less than 9.71% of C++ online submissions for Remove Duplicates from Sorted List II.

// Slowest?
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* p = head;
		vector<ListNode*> vecAll;
		while (p != NULL) {
			vecAll.push_back(p);
			p = p->next;
		}
		int pos = 0;
		while (pos < vecAll.size()) {
			if (pos + 1 < vecAll.size()) {
				if (vecAll[pos]->val != vecAll[pos + 1]->val) { ++pos; }
				else {
					int i = 1;
					while ((pos + i) < vecAll.size()) {
						if (vecAll[pos]->val == vecAll[pos + i]->val) { ++i; }
						else { break; }
					}
					vecAll.erase(vecAll.begin() + pos, vecAll.begin() + pos + i);
					//cout << "T2: " ;
					//for (int i = 0; i < vecAll.size();++i) { cout << vecAll[i]->val << ", "; }
					//cout << endl;
				}
			}
			else { ++pos; }
		}
		if (vecAll.size() == 0) { return NULL; }
		else {
			for (int i = 0; i < vecAll.size();++i) {
				if (i == vecAll.size() - 1) { vecAll[i]->next = NULL; }
				else { vecAll[i]->next = vecAll[i + 1]; }
			}
			return vecAll[0];
		}
	}
};