#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// queue (level order traversal)
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
		if(!root){
			return ans;
		}
		queue<TreeNode*> pre, cur;
		TreeNode *p;
		pre.push(root);
		while(!pre.empty()){
			while(!pre.empty()){
				p = pre.front();
				pre.pop();
				if(p->left){
					cur.push(p->left);
				}
				if(p->right){
					cur.push(p->right);
				}
			}
			ans.push_back(p->val);
			swap(pre, cur);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->right = new TreeNode(4);
	vector<int> ans = sol.rightSideView(root);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
