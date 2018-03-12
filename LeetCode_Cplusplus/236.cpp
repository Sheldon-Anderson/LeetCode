#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

// DFS
// pre order traversal to get path from root to some node, then get answer
class Solution {
private: 
	bool preOrderTraversalGetPath(TreeNode *root, TreeNode *pos, vector<TreeNode*> &path){
		path.push_back(root);
		if(root == pos){
			return true;
		}
		if((root->left && preOrderTraversalGetPath(root->left, pos, path)) 
			|| (root->right && preOrderTraversalGetPath(root->right, pos, path))){
				return true;
			}
		path.pop_back();
		return false;
	}

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root){
			return root;
		}
		vector<TreeNode*> path1, path2;
		if(!preOrderTraversalGetPath(root, p, path1) || !preOrderTraversalGetPath(root, q, path2)){
			return NULL;
		}
		// get answer
		int i = 0;
		// for(; i <= path1.size() - 1; i++){ will cause a Runtime Error! for case: [1,2], node with value 2, node with value 1
		for(; i <= path1.size() - 1 && i <= path2.size() - 1; i++){
			if(path1[i] != path2[i]){
				break;
			}
		}
		return path1[i - 1];
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	/*
	TreeNode *root = new TreeNode(6);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(0);
	root->left->right = new TreeNode(4);
	root->left->right->left = new TreeNode(3);
	root->left->right->right = new TreeNode(5);
	root->right = new TreeNode(8);
	root->right->left = new TreeNode(7);
	root->right->right = new TreeNode(9);
	*/
	cout << "ans: " << sol.lowestCommonAncestor(root, root->left, root)->val;	
	return 0;
}
