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
	vector<vector<int>> ans;
	vector<int> res;

	void DFS(TreeNode *root, int sum, int cnt){
		if(!root){
			return;
		}
		res.push_back(root->val);
		if(!root->left && !root->right && cnt + root->val == sum){
			ans.push_back(res);
		}
		DFS(root->left, sum, cnt + root->val);
		DFS(root->right, sum, cnt + root->val);
		res.pop_back();
	}

public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
		ans.clear();
		res.clear();
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
	vector<vector<int>> ans = sol.pathSum(root, sum);
	// console output
	for(auto &p: ans){
		for(int val: p){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
