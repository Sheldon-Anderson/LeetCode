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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
		if(!root){
			return ans;
		}
		stack<pair<TreeNode*, bool>> st;
		TreeNode* p = root;
		while(p || !st.empty()){
			if(p){
				// 1. visit the left nodes
				st.push(make_pair(p, false));
				p = p->left;
			}
			else{
				// 2. visit the right nodes
				if(st.top().second == false){
					st.top().second = true;
					p = st.top().first->right;
				}
				else{
					// 3. visit the root nodes
					ans.push_back(st.top().first->val);
					st.pop();
				}
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
	vector<int> ans = sol.postorderTraversal(root);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;	
	return 0;
}
