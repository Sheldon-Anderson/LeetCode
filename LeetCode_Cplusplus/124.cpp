#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// DFS: from down to up
class Solution {
private: 
	int ans;
	
	int DFS(TreeNode *root){
		if(!root){
			return 0;
		}
		int sum_left = DFS(root->left);
		int sum_right = DFS(root->right);
		// root is regarded as a root node
		int sum = root->val + max(sum_left, 0) + max(sum_right, 0);
		ans = max(ans, sum);
		// root is regarded as a branch
		return max(root->val, max(root->val + sum_left, root->val + sum_right));
	}

public:
    int maxPathSum(TreeNode* root) {
        ans = INT_MIN;
		DFS(root);
		return ans;
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout << "ans: " << sol.maxPathSum(root) << endl;
	return 0;
}
