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
private: 
	int DFS(TreeNode* root){
		if(!root){
			return 0;
		}
		TreeNode *l = root, *r = root;
		int h = 0;
		while(l && r){
			h++;
			l = l->left;
			r = r->right;
		}
		if(!l && !r){
			return (1 << h) - 1;
		}
		// l && !r
		return 1 + DFS(root->left) + DFS(root->right);
	}

public:
    int countNodes(TreeNode* root) {
        return DFS(root);
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->left->left = new TreeNode(8);
	root->left->left->right = new TreeNode(9);
	root->left->right = new TreeNode(5);
	root->left->right->left = new TreeNode(10);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	cout << "ans: " << sol.countNodes(root) << endl;
	return 0;
}
