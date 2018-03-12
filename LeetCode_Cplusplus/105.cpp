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
	TreeNode* DFS(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie){
		if(ps > pe || is > ie){
			return NULL;
		}
		if(ps == pe || is == ie){
			return new TreeNode(preorder[ps]);
		}
		int val = preorder[ps], pos = -1;
		TreeNode *root = new TreeNode(val);
		for(int i = is; i <= ie; i++){
			if(val == inorder[i]){
				pos = i;
				break;
			}
		}
		if(pos != -1){
			root->left = DFS(preorder, inorder, ps + 1, pe - ie + pos, is, pos - 1);
			root->right = DFS(preorder, inorder, pe - ie + pos + 1, pe, pos + 1, ie);
		}
		return root;
	}

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
		if(n == 0){
			return NULL;
		}
		return DFS(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};

void pre_output(TreeNode* T){
	if(!T){
		return;
	}
	cout << T->val << " ";
	pre_output(T->left);
	pre_output(T->right);
}

void in_output(TreeNode* T){
	if(!T){
		return;
	}
	in_output(T->left);
	cout << T->val << " ";
	in_output(T->right);	
}

int main(){
	Solution sol;
	vector<int> preorder = {1, 2, 4, 5, 3, 6, 7};
	vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
	TreeNode* ans = sol.buildTree(preorder, inorder);
	// console output
	pre_output(ans);
	cout << endl;
	in_output(ans);
	cout << endl;
	return 0;
}
