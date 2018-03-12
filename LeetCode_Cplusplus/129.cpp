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
	int ans;
	
	void DFS(TreeNode *root, int num){
		if(!root){
			return;
		}
		num = 10 * num + root->val;
		if(!root->left && !root->right){
			ans += num;
			return;
		}
		DFS(root->left, num);
		DFS(root->right, num);
	}

public:
    int sumNumbers(TreeNode* root) {
        ans = 0;
		DFS(root, 0);
		return ans;
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	cout << "ans: " << sol.sumNumbers(root) << endl;
	return 0;
}
