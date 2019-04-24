//Given a linked list, rotate the list to the right by k places, where k is non - negative.
//
//Example 1:
//
//Input: 1->2->3->4->5->NULL, k = 2
//	Output : 4->5->1->2->3->NULL
//	Explanation :
//	   rotate 1 steps to the right : 5->1->2->3->4->NULL
//		   rotate 2 steps to the right : 4->5->1->2->3->NULL
//
//		   Example 2 :
//
//		   Input : 0->1->2->NULL, k = 4
//		   Output : 2->0->1->NULL
//		   Explanation :
//	   rotate 1 steps to the right : 2->0->1->NULL
//		   rotate 2 steps to the right : 1->2->0->NULL
//		   rotate 3 steps to the right : 0->1->2->NULL
//		   rotate 4 steps to the right : 2->0->1->NULL
//


//Runtime: 12 ms, faster than 89.38% of C++ online submissions for Rotate List.
//Memory Usage : 9.1 MB, less than 99.26% of C++ online submissions for Rotate List.

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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* p = head;
		vector<ListNode*> vecNodes;
		while (p != NULL) {
			vecNodes.push_back(p);
			p = p->next;
		}
		if (vecNodes.size() < 2) { return head; }
		else {
			int iTime = k % vecNodes.size();
			if (iTime == 0) { return head; }
			else {
				vecNodes[vecNodes.size() - 1]->next = vecNodes[0];
				vecNodes[vecNodes.size() - 1 - iTime]->next = NULL;
				return vecNodes[vecNodes.size() - iTime];
			}
		}
	}
};