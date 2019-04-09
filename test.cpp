#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <functional>

using namespace std;
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
	ListNode* deleteDuplicates(ListNode* head) {
		if (head == NULL || head->next == NULL) { return head; }
		ListNode* p = head, *pHead=NULL, *pPre=NULL;
		bool i = false;
		while (p->next != NULL) {
			if (p->val == p->next->val) {
				i = true;
				p->next = p->next->next;
			}
			else {
				if (!i) {
					if (pPre == NULL) { pHead = p; }
					else { pPre->next = p; }
					pPre = p;
				}
				else { i = false; }
				p = p->next;
			}
		}
		if (pPre != NULL) {
			if (!i) { pPre->next = p; }
			else { pPre->next = NULL; }
		}
		else { if (!i) { pHead = p; } }

		return pHead;
	}
};


int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}