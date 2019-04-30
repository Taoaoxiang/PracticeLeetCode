//Sort a linked list using insertion sort.
//
//
//A graphical example of insertion sort. The partial sorted list (black) initially contains only the first element in the list.
//With each iteration one element (red) is removed from the input data and inserted in-place into the sorted list
// 
//
//Algorithm of Insertion Sort:
//
//    Insertion sort iterates, consuming one input element each repetition, and growing a sorted output list.
//    At each iteration, insertion sort removes one element from the input data, finds the location it belongs within the sorted list, and inserts it there.
//    It repeats until no input elements remain.
//
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

//Runtime: 20 ms, faster than 98.81% of C++ online submissions for Insertion Sort List.
//Memory Usage : 9.8 MB, less than 13.77% of C++ online submissions for Insertion Sort List.
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		ListNode* pD = new ListNode(0);
		pD->next = head;
		ListNode* pPre = pD, * pCur = head;
		while (pCur != NULL) {
			//ListNode* p = pPre;
			//cout << "T0: ";
			//while (p != NULL) {
			//	cout << p->val << ",";
			//	p = p->next;
			//}
			//cout << endl;
			if (pCur->next && pCur->next->val < pCur->val) {
				while (pPre->next && pPre->next->val < pCur->next->val) {
					pPre = pPre->next;
				}
				ListNode* tmp = pCur->next;
				pCur->next = pCur->next->next;
				tmp->next = pPre->next;
				pPre->next = tmp;
				pPre = pD;
			}
			else { pCur = pCur->next; }
		}
		return pD->next;
	}
};

//Runtime: 16 ms, faster than 100.00% of C++ online submissions for Insertion Sort List.
//Memory Usage : 10.1 MB, less than 5.07% of C++ online submissions for Insertion Sort List.

// More shady way!!!
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL) { return head; }
		ListNode* p = head;
		vector<ListNode*> vAll;
		while (p != NULL) {
			vAll.push_back(p);
			p = p->next;
		}
		sort(vAll.begin(), vAll.end(), [](ListNode * a, ListNode * b) {return a->val < b->val;});
		for (int i = 0; i < vAll.size() - 1; ++i) {
			vAll[i]->next = vAll[i + 1];
		}
		vAll[vAll.size() - 1]->next = NULL;

		return vAll[0];
	}
};


//Runtime: 32 ms, faster than 78.66% of C++ online submissions for Insertion Sort List.
//Memory Usage : 10.8 MB, less than 5.07% of C++ online submissions for Insertion Sort List.

// Shady way??? :)
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (head == NULL) { return head; }
		ListNode* p = head;
		set<pair<int, ListNode*>> mAll;
		while (p != NULL) {
			mAll.insert({ p->val, p });
			p = p->next;
		}
		p = new ListNode(0);
		ListNode* pLast = p;
		for (set<pair<int, ListNode*>>::iterator it = mAll.begin(); it != mAll.end(); ++it) {
			//cout << "T: " << it->first << endl;
			pLast->next = it->second;
			pLast = it->second;
		}
		pLast->next = NULL;

		return p->next;
	}
};
