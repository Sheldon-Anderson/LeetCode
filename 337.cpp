#include <bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// DFS
class Solution {
private: 
	int DFS(TreeNode *root, bool flag){
		if(!root){
			return 0;
		}
		int res = 0;
		if(!flag){
			res = max(res, root->val + DFS(root->left, true) + DFS(root->right, true));
		}
		res = max(res, DFS(root->left, false) + DFS(root->right, false));
		return res;
	}

public:
    int rob(TreeNode* root) {
        return DFS(root, false);
    }
};

int main(int argc, char** argv){
	Solution sol;
	/*
	TreeNode *T = new TreeNode(3);
	T->left = new TreeNode(2);
	T->left->right = new TreeNode(3);
	T->right = new TreeNode(3);
	T->right->right = new TreeNode(1);
	*/
	TreeNode *T = new TreeNode(3);
	T->left = new TreeNode(4);
	T->left->left = new TreeNode(1);
	T->left->right = new TreeNode(3);
	T->right = new TreeNode(5);
	T->right->right = new TreeNode(1);
	cout << "ans: " << sol.rob(T) << endl;
	return 0;
}
