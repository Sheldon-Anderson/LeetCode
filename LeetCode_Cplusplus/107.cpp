#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// queue
class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root){
			return vector<vector<int>>();
		}
		vector<vector<int>> ans;
		vector<int> res;
		queue<TreeNode*> pre, cur;
		TreeNode *p;
		pre.push(root);
		while(!pre.empty()){
			while(!pre.empty()){
				p = pre.front();
				pre.pop();
				res.push_back(p->val);
				if(p->left){
					cur.push(p->left);
				}
				if(p->right){
					cur.push(p->right);
				}
			}
			ans.push_back(res);
			swap(pre, cur);
			res.clear();
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(3);
	root->left = new TreeNode(9);
	root->right = new TreeNode(20);
	root->right->left = new TreeNode(15);
	root->right->right = new TreeNode(7);
	vector<vector<int>> ans = sol.levelOrderBottom(root);
	// console output
	for(auto &p: ans){
		for(int val: p){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
