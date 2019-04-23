#include "include_LeetCode.h"


//
//class Solution {
//public:
//	int numDecodings(string s) {
//		
//		int sSize = s.size();
//		if (sSize == 0) { return 0; }
//		else if (sSize == 1) { 
//			if (s[0] == '0') { return 0; } 
//			else { return 1; }
//		}
//		int rtn = 0;
//		for (int i = 0; i < sSize; ++i) {
//			if (i == 0) {
//				if (s[i] == '0') { return 0; }
//				else if (s[i] == '1') { rtn += 2; }
//				else if (s[i] == '2') { 
//					if (s[i + 1] >= '0' && s[i + 1] <= '6') { rtn += 2; }
//					else { rtn += 1; }
//				}
//				else { rtn += 1; }
//			}
//			else if (i == sSize - 1) {
//				if (s[i] == '0') {
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
//					else { return 0; }
//				}
//				else {
//					if (s[i - 1] == '1') { rtn += 2; }
//					else if (s[i - 1] == '2' && (s[i] >= '1'&&s[i] <= '6')) { rtn += 2; }
//					else { rtn += 1; }
//				}
//			}
//			else {
//				if (s[i] == '0') {
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
//					else { return 0; }
//				}
//				else if (s[i] == '1') { 
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 3; }
//					else { rtn += 2; }
//				}
//				else if (s[i] == '2') {
//					if (s[i - 1] == '1' || s[i - 1] == '2') { rtn += 1; }
//					if (s[i + 1] >= '0' && s[i + 1] <= '6') { rtn += 1; }
//					rtn += 1;
//				}
//				else { 
//					if (s[i - 1] == '1' ) { rtn += 2; } 
//					else if (s[i - 1] == '2' && (s[i]>='1'&&s[i] <= '6')) { rtn += 2; }
//					else { rtn += 1; }
//				}
//			}
//		}
//		return rtn-sSize-1;
//	}
//};
//


class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) { return root; }
		Node* nHead = root;
		while (nHead != NULL) {
			Node* n0 = nHead;
			nHead = NULL;
			Node* nLast = NULL;
			while (n0 != NULL && (n0->left == NULL && n0->right == NULL)) { n0 = n0->next; }
			if (n0 == NULL) { continue; }
			if (n0->left != NULL && n0->right == NULL) { 
				nHead = n0->left; 
				nLast = n0->left;
			}
			else if (n0->left == NULL && n0->right != NULL) { 
				nHead = n0->right; 
				nLast = n0->right;
			}
			else if (n0->left != NULL && n0->right != NULL) { 
				n0->left->next = n0->right;
				nHead = n0->left; 
				nLast = n0->right;
			}
			Node* n1 = n0->next;
			while (n1 != NULL) {
				while (n1 != NULL && (n1->left == NULL && n1->right == NULL)) { n1 = n1->next; }
				if (n1 == NULL) { continue; }
				if (n1->left != NULL && n1->right == NULL) {
					nLast->next = n1->left;
					nLast = n1->left;
				}
				else if (n1->left == NULL && n1->right != NULL) {
					nLast->next = n1->right;
					nLast = n1->right;
				}
				else if (n1->left != NULL && n1->right != NULL) {
					nLast->next = n1->left;
					n1->left->next = n1->right;
					nLast = n1->right;
				}
				n1 = n1->next;
			}
		}
		return root;
	}
};

int main() {



	std::cout << "Wuzup world!" << std::endl;
	return 0;
}