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
    int maxDepth(TreeNode* root) {
        if(!root){
			return 0;
		}
		return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	// root->right->right = new TreeNode(7);	
	root->right->left->right = new TreeNode(7);
	// console output
	cout << "ans: " << sol.maxDepth(root) << endl;
	return 0;
}
