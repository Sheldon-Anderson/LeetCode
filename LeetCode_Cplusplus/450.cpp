#include<bits/stdc++.h>

using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/*
// DFS 1
// find the max value in the left subtree
class Solution {
private: 
	int getMaxVal(TreeNode *T){
		while(T->right){
			T = T->right;
		}
		return T->val;
	}

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
			return NULL;
		}
		if(root->val == key){
			if(!root->left && !root->right){
				delete(root);
				return NULL;
			}
			else if(root->left && !root->right){
				TreeNode *L = root->left;
				delete(root);
				return L;
			}
			else if(!root->left && root->right){
				TreeNode *R = root->right;
				delete(root);
				return R;
			}
			else{
				int maxVal = getMaxVal(root->left);
				root->val = maxVal;
				root->left = deleteNode(root->left, maxVal);
			}
		}
		else if(root->val < key){
			root->right = deleteNode(root->right, key);
		}
		else if(root->val > key){
			root->left = deleteNode(root->left, key);
		}
		return root;
    }
};
*/

// DFS 2
// find the min value in the right subtree
class Solution {
private: 
	int getMinVal(TreeNode *T){
		while(T->left){
			T = T->left;
		}
		return T->val;
	}

public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root){
			return NULL;
		}
		if(root->val == key){
			if(!root->left && !root->right){
				delete(root);
				return NULL;
			}
			else if(root->left && !root->right){
				TreeNode *L = root->left;
				delete(root);
				return L;
			}
			else if(!root->left && root->right){
				TreeNode *R = root->right;
				delete(root);
				return R;
			}
			else{
				int minVal = getMinVal(root->right);
				root->val = minVal;
				root->right = deleteNode(root->right, minVal);
			}
		}
		else if(root->val < key){
			root->right = deleteNode(root->right, key);
		}
		else if(root->val > key){
			root->left = deleteNode(root->left, key);
		}
		return root;
    }
};

void preout(TreeNode *T){
	if(!T){
		return;
	}
	cout << T->val << " ";
	preout(T->left);
	preout(T->right);
}

int main(int argc, char** argv){
	Solution sol;
	TreeNode *T = new TreeNode(5);
	T->left = new TreeNode(3);
	T->left->left = new TreeNode(2);
	T->left->right = new TreeNode(4);
	T->right = new TreeNode(6);
	T->right->right = new TreeNode(7);
	// out 1
	preout(T);
	cout << endl;
	// out 2
	int key = 5;
	TreeNode *ans = sol.deleteNode(T, key);
	preout(T);
	cout << endl;
	return 0;
}
