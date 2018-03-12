#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/*
// DFS
// Accepted
class Solution {
private: 
	int ans;

	void DFS(TreeNode *root, int sum, int res, bool flag){
		if(!root){
			return;
		}
		if(!flag){
			DFS(root->left, sum, res, false);
			DFS(root->right, sum, res, false);
		}
		// check
		if(res + root->val == sum){
			ans++;
		}
		DFS(root->left, sum, res + root->val, true);
		DFS(root->right, sum, res + root->val, true);
	}

public:
    int pathSum(TreeNode* root, int sum) {
        ans = 0;
		DFS(root, sum, 0, false);
		return ans;
    }
};
*/

// two level DFS
class Solution{
private: 
	int DFS(TreeNode *root, int sum, int res){
		int ans = 0;
		if(!root){
			return 0;
		}
		if(res + root->val == sum){
			ans++;
		}
		ans += DFS(root->left, sum, res + root->val);
		ans += DFS(root->right, sum, res + root->val);
		return ans;
	}

public:
    int pathSum(TreeNode* root, int sum) {
		if(!root){
			return 0;
		}
		return DFS(root, sum, 0) + pathSum(root->left, sum) + pathSum(root->right, sum);
	}
};

int main(int argc, char** argv){
	Solution sol;
	TreeNode *root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->left->left = new TreeNode(3);
	root->left->left->left = new TreeNode(3);
	root->left->left->right = new TreeNode(-2);
	root->left->right = new TreeNode(2);
	root->left->right->right = new TreeNode(1);
	root->right = new TreeNode(-3);
	root->right->right = new TreeNode(11);
	int sum = 8;
	cout << "ans: " <<sol.pathSum(root, sum) << endl;
	return 0;
}
