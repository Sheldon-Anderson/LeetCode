#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
public:
    int minDepth(TreeNode* root) {
		if(!root){
			return 0;
		}
		if(!root->left && !root->right){
			return 1;
		}
		if(!root->left && root->right){
			return 1 + minDepth(root->right);
		}
		if(root->left && !root->right){
			return 1 + minDepth(root->left);
		}
		return 1 + min(minDepth(root->left), minDepth(root->right));
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);	
	root->left->left->left = new TreeNode(8);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	cout << "ans: " << sol.minDepth(root) << endl;
	return 0;
}
