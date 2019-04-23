//Runtime: 428 ms, faster than 43.56% of C++ online submissions for Populating Next Right Pointers in Each Node II.
//Memory Usage : 66.4 MB, less than 56.31% of C++ online submissions for Populating Next Right Pointers in Each Node II.

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) { return root; }
		Node* n0 = root;
		Node* nLast = NULL;
		Node* nHead = root->left;
		while (n0 != NULL || nHead != NULL) {
			if (n0 == NULL) {
				n0 = nHead;
				nLast = NULL;
				nHead = NULL;
				continue;
			}
			if (n0->left != NULL) {
				if (nLast != NULL) { nLast->next = n0->left; }
				else { nHead = n0->left; }
				nLast = n0->left;
			}
			if (n0->right != NULL) {
				if (nLast != NULL) { nLast->next = n0->right; }
				else { nHead = n0->right; }
				nLast = n0->right;
			}
			n0 = n0->next;
		}
		return root;
	}
};

//Runtime: 424 ms, faster than 56.18% of C++ online submissions for Populating Next Right Pointers in Each Node II.
//Memory Usage : 66.5 MB, less than 55.34% of C++ online submissions for Populating Next Right Pointers in Each Node II.

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

//Runtime: 420 ms, faster than 71.97% of C++ online submissions for Populating Next Right Pointers in Each Node II.
//Memory Usage : 68.1 MB, less than 5.34% of C++ online submissions for Populating Next Right Pointers in Each Node II.

class Solution {
public:
	Node* connect(Node* root) {
		queue<Node*> qNodes;
		qNodes.push(root);
		while (qNodes.size() > 0) {
			queue<Node*> qNodesTemp;
			while (qNodes.size() > 0) {
				Node* n0 = qNodes.front();
				qNodes.pop();
				if (n0 == NULL) { continue; }
				while (qNodes.size() > 0 && qNodes.front() == NULL) { qNodes.pop(); }
				if (qNodes.size() > 0) { n0->next = qNodes.front(); }
				qNodesTemp.push(n0->left);
				qNodesTemp.push(n0->right);
			}
			qNodes = qNodesTemp;
		}
		return root;
	}
};
