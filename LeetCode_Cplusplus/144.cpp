#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// stack
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
		if(!root){
			return ans;
		}
		stack<TreeNode*> st;
		TreeNode *p = root;
		while(p || !st.empty()){
			if(p){
				ans.push_back(p->val);
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				st.pop();
				p = p->right;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	vector<int> ans = sol.preorderTraversal(root);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
