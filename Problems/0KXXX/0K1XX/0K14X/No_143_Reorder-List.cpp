//Given a singly linked list L: L0→L1→…→Ln-1→Ln,
//reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
//You may not modify the values in the list's nodes, only nodes itself may be changed.
//
//Example 1:
//
//Given 1->2->3->4, reorder it to 1->4->2->3.
//
//Example 2:
//
//Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
//


//Runtime: 48 ms, faster than 99.59% of C++ online submissions for Reorder List.
//Memory Usage : 12.1 MB, less than 73.12% of C++ online submissions for Reorder List.

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL || head->next == NULL) { return; }
		// Step1: get the second half
		// Firt half ends at pPre.next
		// New head: pSlow
		ListNode* pSlow = head, * pFast = head, * pPre = NULL;
		while (pFast && pFast->next) {
			pPre = pSlow;
			pSlow = pSlow->next;
			pFast = pFast->next->next;
		}
		pPre->next = NULL;
		// Step2: reverse the second half
		// New head: pFast
		pPre = pSlow;
		pFast = pSlow;
		while (pFast->next) {
			ListNode* tmp = pFast;
			pFast = pFast->next;
			tmp->next = pSlow;
			pSlow = tmp;
		}
		pFast->next = pSlow;
		pPre->next = NULL;
		// Step3: stitch them together
		pSlow = head;
		while (pSlow->next) {
			ListNode* tmp = pSlow;
			pSlow = pSlow->next;
			tmp->next = pFast;
			tmp = pFast;
			pFast = pFast->next;
			tmp->next = pSlow;
		}
		pSlow->next = pFast;
		//ListNode* p = head;
		//while (p!=NULL) {
		//	cout << "T0: p=>" << p->val << endl;
		//	p = p->next;
		//}

		return;
	}
};

//Runtime: 888 ms, faster than 5.05% of C++ online submissions for Reorder List.
//Memory Usage : 13.6 MB, less than 5.38% of C++ online submissions for Reorder List.

class Solution {
public:
	ListNode* reS(ListNode* head, ListNode* tail, int dir) {
		if (head == tail) { return NULL; }
		if (dir == 1) {
			tail->next = reS(head->next, tail, dir * -1);
			return tail;
		}
		else {
			ListNode* p = head;
			while (p->next != tail) { p = p->next; }
			head->next = reS(head, p, dir * -1);
			return head;
		}
	}

	void reorderList(ListNode * head) {
		if (head == NULL) { return; }
		ListNode* tail = head;
		while (tail->next != NULL) { tail = tail->next; }
		head->next = reS(head, tail, 1);
		return;
	}
};

//Runtime: 48 ms, faster than 99.59% of C++ online submissions for Reorder List.
//Memory Usage : 13.5 MB, less than 5.38% of C++ online submissions for Reorder List.

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL) { return; }
		vector<ListNode*> vAll;
		ListNode* p = head;
		while (p != NULL) {
			vAll.push_back(p);
			p = p->next;
		}
		int dir = 1;
		int p0 = 0, p1 = vAll.size() - 1;
		for (; p0 < p1; dir *= -1) {
			if (dir == 1) {
				vAll[p0]->next = vAll[p1];
				++p0;
			}
			else if (dir == -1) {
				vAll[p1]->next = vAll[p0];
				--p1;
			}
		}
		vAll[p0]->next = NULL;
		return;
	}
};

//Runtime: 68 ms, faster than 13.37% of C++ online submissions for Reorder List.
//Memory Usage : 13.3 MB, less than 10.22% of C++ online submissions for Reorder List.

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL) { return; }
		vector<ListNode*> vAll;
		ListNode* p = head;
		while (p != NULL) {
			vAll.push_back(p);
			p = p->next;
		}
		int dir = -1;
		p = head;
		for (int p0 = 1, p1 = vAll.size() - 1; p0 <= p1; dir *= -1) {
			if (dir == 1) {
				p->next = vAll[p0];
				++p0;
			}
			else if (dir == -1) {
				p->next = vAll[p1];
				--p1;
			}
			p = p->next;
		}
		p->next = NULL;
		return;
	}
};


//Runtime: 776 ms, faster than 6.65% of C++ online submissions for Reorder List.
//Memory Usage : 13.3 MB, less than 10.22% of C++ online submissions for Reorder List.

class Solution {
public:
	void reorderList(ListNode* head) {
		if (head == NULL) { return; }
		vector<ListNode*> vAll;
		ListNode* p = head;
		while (p != NULL) {
			vAll.push_back(p);
			p = p->next;
		}
		int dir = -1;
		p = vAll.front();
		vAll.erase(vAll.begin());
		while (vAll.size() > 0) {
			ListNode* tmp;
			if (dir == 1) {
				tmp = vAll.front();
				vAll.erase(vAll.begin());
			}
			else if (dir == -1) {
				tmp = vAll.back();
				vAll.pop_back();
			}
			p->next = tmp;
			dir *= -1;
			p = p->next;
		}
		p->next = NULL;
		return;
	}
};