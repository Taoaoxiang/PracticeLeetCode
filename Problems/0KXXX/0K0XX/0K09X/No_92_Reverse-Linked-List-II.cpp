//Reverse a linked list from position m to n.Do it in one - pass.
//
//Note: 1 ≤ m ≤ n ≤ length of list.
//
//	Example :
//
//	Input : 1->2->3->4->5->NULL, m = 2, n = 4
//	Output : 1->4->3->2->5->NULL
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

//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
//Memory Usage : 8.5 MB, less than 100.00% of C++ online submissions for Reverse Linked List II.

// This problem asks for one-pass solution.
// This solution works. :)
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) { return head; }
		int i = 1;
		// Left: Head->End
		// Mid: Head->End
		// Right: Head
		ListNode *p = head, *pLEnd = NULL, *pMHead = NULL, *pCur = NULL, *pRHead = NULL;
		while (i <= n) {
			if (i < m - 1) { p = p->next; }
			else if (i == m - 1) {
				pLEnd = p;
				p = p->next;
			}
			else if (i == m) {
				pRHead = p;
				pMHead = p;
				p = p->next;
			}
			else if (i > m && i < n) {
				pCur = p;
				p = p->next;
				pCur->next = pMHead;
				pMHead = pCur;
			}
			else if (i == n) {
				pRHead->next = p->next;
				pCur = p;
				if (pLEnd != NULL) { pLEnd->next = pCur; }
				pCur->next = pMHead;
				pMHead = pCur;
			}
			++i;
		}
		if (pLEnd == NULL) { return pMHead; }
		else { return head; }
	}
};


//Runtime: 4 ms, faster than 100.00% of C++ online submissions for Reverse Linked List II.
//Memory Usage : 8.7 MB, less than 98.13% of C++ online submissions for Reverse Linked List II.

class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) { return head; }
		int i = 0;
		ListNode *p = head, *pTmp;
		vector<ListNode*> vec;
		while (p != NULL) {
			vec.push_back(p);
			p = p->next;
		}
		for (int iL = m - 1, iR = n - 1; iL < iR; ++iL, --iR) {
			pTmp = vec[iL];
			vec[iL] = vec[iR];
			vec[iR] = pTmp;
		}
		for (int i = 0; i < vec.size(); ++i) {
			if (i + 1 < vec.size()) { vec[i]->next = vec[i + 1]; }
			else { vec[i]->next = NULL; }
		}

		return vec[0];
	}
};