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
	bool ans;
	void DFS(TreeNode *root, int sum, int res){
		if(ans || !root){
			return;
		}
		if(!root->left && !root->right && res + root->val == sum){
			ans = true;
			return;
		}
		DFS(root->left, sum, res + root->val);
		DFS(root->right, sum, res + root->val);
	}

public:
    bool hasPathSum(TreeNode* root, int sum) {
        ans = false;
		if(!root){
			return ans;
		}
		DFS(root, sum, 0);
		return ans;
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(5);
	root->left = new TreeNode(4);
	root->left->left = new TreeNode(11);
	root->left->left->left = new TreeNode(7);
	root->left->left->right = new TreeNode(2);	// 2
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(13);
	root->right->right = new TreeNode(4);
	root->right->right->left = new TreeNode(5);
	root->right->right->right = new TreeNode(1);
	int sum = 22;
	cout << "ans: " << sol.hasPathSum(root, sum) << endl;
	return 0;
}
