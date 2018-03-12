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
	TreeNode *DFS(vector<int>& inorder, vector<int>& postorder, int is, int ie, int ps, int pe){
		if(is > ie || ps > pe){
			return NULL;
		}
		if(is == ie || ps == pe){
			return new TreeNode(inorder[is]);
		}
		int val = postorder[pe], pos = -1;
		TreeNode *root = new TreeNode(val);
		for(int i = is; i <= ie; i++){
			if(val == inorder[i]){
				pos = i;
				break;
			}
		}
		if(pos != -1){
			root->left = DFS(inorder, postorder, is, pos - 1, ps, ps + pos - is - 1);
			root->right = DFS(inorder, postorder, pos + 1, ie, ps + pos - is, pe - 1);
		}
		return root;
	}

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
		if(n == 0){
			return NULL;
		}
		return DFS(inorder, postorder, 0, n - 1, 0, n - 1);
    }
};

void in_output(TreeNode *T){
	if(!T){
		return;
	}
	in_output(T->left);
	cout << T->val << " ";
	in_output(T->right);
}

void post_output(TreeNode *T){
	if(!T){
		return;
	}
	post_output(T->left);
	post_output(T->right);
	cout << T->val << " ";
}

int main(){
	Solution sol;
	vector<int> inorder = {4, 2, 5, 1, 6, 3, 7};
	vector<int> postorder = {4, 5, 2, 6, 7, 3, 1};
	TreeNode* ans = sol.buildTree(inorder, postorder);
	// console output
	in_output(ans);
	cout << endl;
	post_output(ans);
	cout << endl;
	return 0;
}
