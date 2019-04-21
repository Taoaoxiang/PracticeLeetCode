//Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
//
//For this problem, a height - balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
//
//Example:
//
//Given the sorted linked list : [-10, -3, 0, 5, 9],
//
//One possible answer is : [0, -3, 9, -10, null, 5], which represents the following height balanced BST :
//
//0
/// \
//- 3   9
///   /
//-10  5
//


//Runtime: 32 ms, faster than 100.00% of C++ online submissions for Convert Sorted List to Binary Search Tree.
//Memory Usage : 23.4 MB, less than 97.10% of C++ online submissions for Convert Sorted List to Binary Search Tree.

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		while (head != NULL) {
			nums.push_back(head->val);
			head = head->next;
		}
		if (nums.size() == 0) { return NULL; }
		queue<TreeNode*> qTrees;
		queue<pair<int, int>> qPairs;
		int iM = (0 + nums.size() - 1) / 2;
		TreeNode* root = new TreeNode(nums[iM]);
		qTrees.push(root);
		qPairs.push({ 0, iM - 1 });
		qPairs.push({ iM + 1, nums.size() - 1 });
		while (qTrees.size() > 0) {
			queue<TreeNode*> qTreesTemp;
			int mi = -1;
			while (qTrees.size() > 0) {
				TreeNode* ro = qTrees.front();
				qTrees.pop();
				pair<int, int> pL = qPairs.front();
				qPairs.pop();
				pair<int, int> pR = qPairs.front();
				qPairs.pop();
				if (pL.first <= pL.second) {
					mi = (pL.first + pL.second) / 2;
					ro->left = new TreeNode(nums[mi]);
					if (pL.first < pL.second) {
						qTreesTemp.push(ro->left);
						qPairs.push({ pL.first, mi - 1 });
						qPairs.push({ mi + 1, pL.second });
					}
				}
				if (pR.first <= pR.second) {
					mi = (pR.first + pR.second) / 2;
					ro->right = new TreeNode(nums[mi]);
					if (pR.first < pR.second) {
						qTreesTemp.push(ro->right);
						qPairs.push({ pR.first, mi - 1 });
						qPairs.push({ mi + 1, pR.second });
					}
				}
			}
			qTrees = qTreesTemp;
		}

		return root;
	}
};

//Runtime: 32 ms, faster than 100.00% of C++ online submissions for Convert Sorted List to Binary Search Tree.
//Memory Usage : 24.6 MB, less than 38.16% of C++ online submissions for Convert Sorted List to Binary Search Tree.

// Recursion with a vector, looks faster :)
class Solution {
public:
	TreeNode* reSearch(int iStart, int iEnd, vector<int>& nums) {
		//cout <<"iStart=>" << iStart <<", iEnd=>" <<iEnd<<endl;
		if (iStart > iEnd) { return NULL; }
		int iM = (iStart + iEnd) / 2;
		TreeNode* root = new TreeNode(nums[iM]);
		if (iStart == iEnd) { return root; }
		root->left = reSearch(iStart, iM - 1, nums);
		root->right = reSearch(iM + 1, iEnd, nums);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		vector<int> nums;
		while (head != NULL) {
			nums.push_back(head->val);
			head = head->next;
		}
		if (nums.size() == 0) { return NULL; }
		TreeNode* root = reSearch(0, nums.size() - 1, nums);
		return root;
	}
};

//Runtime: 48 ms, faster than 19.02% of C++ online submissions for Convert Sorted List to Binary Search Tree.
//Memory Usage : 24.5 MB, less than 52.17% of C++ online submissions for Convert Sorted List to Binary Search Tree.

// Recursive version looks slow???
class Solution {
public:
	TreeNode* reM(ListNode* head, ListNode* tail) {
		if (head == tail) { return NULL; }
		else if (head->next == tail) { return new TreeNode(head->val); }
		ListNode* mi = head, *mi2 = head;
		while (mi2 != tail && mi2->next != tail) {
			mi = mi->next;
			mi2 = mi2->next->next;
		}
		TreeNode* root = new TreeNode(mi->val);
		root->left = reM(head, mi);
		root->right = reM(mi->next, tail);
		return root;
	}

	TreeNode* sortedListToBST(ListNode* head) {
		TreeNode* root = reM(head, NULL);
		return root;
	}
};