// All the needed headers for LeetCode
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <functional>
#include <stack>
#include <queue>
#include <deque>

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/*
// Definition for a Node.
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};
*/
class Node {
public:
	int val;
	Node* left;
	Node* right;
	Node* next;

	Node() {}

	Node(int _val, Node* _left, Node* _right, Node* _next) {
		val = _val;
		left = _left;
		right = _right;
		next = _next;
	}
};

class TRIE {
	bool end = false;
	unordered_map<char, TRIE*> children;
public:
	TRIE() {}
	void insert(string &word) {
		TRIE* root = this;
		if (word.size() == 0) { return; }
		for (int i = 0; i < word.size();++i) {
			if (root->children[word[i]] == NULL) { root->children[word[i]] = new TRIE(); }
			root = root->children[word[i]];
		}
		root->end = true;
	}
	bool find(string &word) {
		TRIE* root = this;
		for (int i = 0; i < word.size();++i) {
			root = root->children[word[i]];
			if (root == NULL) { return false; }
		}
		return root->end;
	}
};