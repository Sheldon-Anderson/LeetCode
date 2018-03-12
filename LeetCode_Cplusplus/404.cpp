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
	int ans;
	
	void DFS(TreeNode* root){
		if(root){
			if(root->left){
				if(!root->left->left && !root->left->right){
					ans += root->left->val;
				}
				else{
					DFS(root->left);
				}
			}
			if(root->right){
				DFS(root->right);
			}
		}
	}

public:
    int sumOfLeftLeaves(TreeNode* root) {
		ans = 0;
        if(!root){
			return ans;
		}
		DFS(root);
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	TreeNode *T = new TreeNode(3);
	T->left = new TreeNode(9);
	T->right = new TreeNode(20);
	T->right->left = new TreeNode(15);
	T->right->right = new TreeNode(7);
	cout << "ans: " << sol.sumOfLeftLeaves(T) << endl;
	return 0;
}
