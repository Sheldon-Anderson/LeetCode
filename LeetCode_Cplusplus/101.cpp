#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
private: 
	bool DFS(TreeNode *t1, TreeNode* t2){
		if(!t1 && !t2){
			return true;
		}
		if(!t1 || !t2){
			return false;
		}
		return (t1->val == t2->val) && DFS(t1->left, t2->right) && DFS(t1->right, t2->left);
	}

public:
    bool isSymmetric(TreeNode* root) {
        if(!root){
			return true;
		}
		return DFS(root->left, root->right);
    }
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(2);
	root->right->left = new TreeNode(4);
	root->right->right = new TreeNode(3);
	cout << "ans: " << sol.isSymmetric(root) << endl;
	return 0;
}
