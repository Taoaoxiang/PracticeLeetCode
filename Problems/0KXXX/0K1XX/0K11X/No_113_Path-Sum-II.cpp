//Given a binary tree and a sum, find all root - to - leaf paths where each path's sum equals the given sum.
//
//Note: A leaf is a node with no children.
//
//	Example :
//
//	Given the below binary tree and sum = 22,
//
//	5
//	/ \
//	4   8
//	/   / \
//	11  13  4
//	/ \ / \
//	7    2  5   1
//
//	Return:
//
//[
//	[5, 4, 11, 2],
//	[5, 8, 4, 5]
//]
//


//Runtime: 32 ms, faster than 37.33% of C++ online submissions for Path Sum II.
//Memory Usage : 31.7 MB, less than 37.59% of C++ online submissions for Path Sum II.

class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> rtn;
		if (root == NULL) { return rtn; }
		stack<TreeNode*> sTrees;
		stack<vector<int>> sVe;
		sTrees.push(root);
		sVe.push({});
		while (sTrees.size() > 0) {
			TreeNode* ro = sTrees.top();
			vector<int> ve = sVe.top();
			sTrees.pop();
			sVe.pop();
			ve.push_back(ro->val);
			int sum2 = 0;
			for (int i = 0; i < ve.size();++i) { sum2 += ve[i]; }
			if (ro->left == NULL && ro->right == NULL) {
				if (sum == sum2) { rtn.push_back(ve); }
			}
			else if (ro->left != NULL && ro->right == NULL) {
				sVe.push(ve);
				sTrees.push(ro->left);
			}
			else if (ro->left == NULL && ro->right != NULL) {
				sVe.push(ve);
				sTrees.push(ro->right);
			}
			else {
				sVe.push(ve);
				sVe.push(ve);
				sTrees.push(ro->left);
				sTrees.push(ro->right);
			}
		}
		return rtn;
	}
};

//Runtime: 40 ms, faster than 21.76% of C++ online submissions for Path Sum II.
//Memory Usage : 38.2 MB, less than 12.77% of C++ online submissions for Path Sum II.

class Solution {
public:
	void reS(TreeNode* root, int sum, vector<int> ve, vector<vector<int>>& rtn) {
		if (root == NULL) { return; }
		ve.push_back(root->val);
		if (root->val == sum && (root->left == NULL && root->right == NULL)) {
			rtn.push_back(ve);
		}
		else {
			reS(root->left, sum - root->val, ve, rtn);
			reS(root->right, sum - root->val, ve, rtn);
		}
		return;
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> rtn;
		reS(root, sum, {}, rtn);
		return rtn;
	}
};
