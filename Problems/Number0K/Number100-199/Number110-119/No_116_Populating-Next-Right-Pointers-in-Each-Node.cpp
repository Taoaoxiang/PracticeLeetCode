//You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:
//
//struct Node {
//  int val;
//  Node *left;
//  Node *right;
//  Node *next;
//}
//
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//
// 
//
//Example:
//
//Input: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":null,"right":null,"val":4},"next":null,"right":{"$id":"4","left":null,"next":null,"right":null,"val":5},"val":2},"next":null,"right":{"$id":"5","left":{"$id":"6","left":null,"next":null,"right":null,"val":6},"next":null,"right":{"$id":"7","left":null,"next":null,"right":null,"val":7},"val":3},"val":1}
//
//Output: {"$id":"1","left":{"$id":"2","left":{"$id":"3","left":null,"next":{"$id":"4","left":null,"next":{"$id":"5","left":null,"next":{"$id":"6","left":null,"next":null,"right":null,"val":7},"right":null,"val":6},"right":null,"val":5},"right":null,"val":4},"next":{"$id":"7","left":{"$ref":"5"},"next":null,"right":{"$ref":"6"},"val":3},"right":{"$ref":"4"},"val":2},"next":null,"right":{"$ref":"7"},"val":1}
//
//Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B.
//
// 
//
//Note:
//
//    You may only use constant extra space.
//    Recursive approach is fine, implicit stack space does not count as extra space for this problem.
//


//Runtime: 64 ms, faster than 82.82% of C++ online submissions for Populating Next Right Pointers in Each Node.
//Memory Usage : 27.4 MB, less than 8.61% of C++ online submissions for Populating Next Right Pointers in Each Node.

class Solution {
public:
	Node* connect(Node* root) {
		if (root == NULL) { return root; }
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