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
	TreeNode* DFS(TreeNode *root, int minVal, int maxVal){
		if(root->val == minVal){
			return root;
		}
		if(root->val == maxVal){
			return root;
		}
		if(root->val > minVal && root->val < maxVal){
			return root;
		}
		TreeNode* ans = NULL;
		if(root->val > maxVal && root->left){
			ans = DFS(root->left, minVal, maxVal);
		}
		else if(root->val < minVal && root->right){
			ans = DFS(root->right, minVal, maxVal);
		}
		return ans;
	}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        int minVal = min(p->val, q->val);
		int maxVal = max(p->val, q->val);
		return DFS(root, minVal, maxVal);
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	cout << "ans: " << sol.lowestCommonAncestor(root, root->left, root->left->right->right)->val;
	return 0;
}
