//Runtime: 8 ms, faster than 100.00% of C++ online submissions for Merge Two Sorted Lists.
//Memory Usage : 9 MB, less than 99.71% of C++ online submissions for Merge Two Sorted Lists.


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

class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == NULL && l2 == NULL) { return NULL; }
		else if (l1 == NULL) { return l2; }
		else if (l2 == NULL) { return l1; }
		ListNode* rtn = NULL;
		vector<ListNode*> vecNodes;
		ListNode* p1 = l1;
		ListNode* p2 = l2;
		while ((p1 != NULL) || (p2 != NULL)) {
			if (p1 == NULL) {
				vecNodes.push_back(p2);
				p2 = p2->next;
			}
			else if (p2 == NULL) {
				vecNodes.push_back(p1);
				p1 = p1->next;
			}
			else if ((p1 != NULL) && (p2 != NULL)) {
				if ((p1->val > p2->val)) {
					vecNodes.push_back(p2);
					p2 = p2->next;
				}
				else if (p1->val <= p2->val) {
					vecNodes.push_back(p1);
					p1 = p1->next;
				}
			}
		}
		for (int i = 0;i != vecNodes.size();++i) {
			if (i + 1 == vecNodes.size()) { vecNodes[i]->next = NULL; }
			else { vecNodes[i]->next = vecNodes[i + 1]; }
		}
		rtn = vecNodes[0];

		return rtn;
	}
};