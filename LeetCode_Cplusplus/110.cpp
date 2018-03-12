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
	int DFS(TreeNode* root){
		if(!root){
			return 0;
		}
		int depth_left = DFS(root->left);
		int depth_right = DFS(root->right);
		if(depth_left == -1 || depth_right == -1 || abs(depth_left - depth_right) > 1){
			return -1;
		}
		return max(depth_left, depth_right) + 1;
	}

public:
    bool isBalanced(TreeNode* root) {
        return DFS(root) >= 0;
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(3);
	// root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	cout << "ans: " << sol.isBalanced(root) << endl;
	return 0;
}
