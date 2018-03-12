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
    void flatten(TreeNode* root) {
        if(!root){
			return;
		}
		if(!root->left && !root->right){
			return;
		}
		else if(!root->left && root->right){
			flatten(root->right);
		}
		else if(root->left && !root->right){
			root->right = root->left;
			root->left = NULL;
			flatten(root->right);
		}
		else if(root->left && root->right){
			TreeNode *p = root->left;
			while(p->right){
				p = p->right;
			}
			p->right = root->right;
			root->right = root->left;
			root->left = NULL;
			flatten(root->right);
		}
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(4);
	root->right = new TreeNode(5);
	root->right->right = new TreeNode(6);
	// console output 1
	TreeNode *p = root;
	while(p){
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;
	sol.flatten(root);
	// console output 2
	p = root;
	while(p){
		cout << p->val << " ";
		p = p->right;
	}
	cout << endl;
	return 0;
}
