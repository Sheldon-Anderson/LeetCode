#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// DFS
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
			return root;
		}
		TreeNode *L = invertTree(root->left);
		TreeNode *R = invertTree(root->right);
		root->left = R;
		root->right = L;
		return root;
    }
};

void output(TreeNode *T){
	if(!T){
		return;
	}
	cout << T->val << " ";
	output(T->left);
	output(T->right);
}

int main(){
	Solution sol;
	TreeNode *T = new TreeNode(4);
	T->left = new TreeNode(2);
	T->left->left = new TreeNode(1);
	T->left->right = new TreeNode(3);
	T->right = new TreeNode(7);
	T->right->left = new TreeNode(6);
	T->right->right = new TreeNode(9);
	// out 1
	output(T);
	cout << endl;
	// out 2
	TreeNode *ans = sol.invertTree(T);
	output(ans);
	cout << endl;
	return 0;
}
