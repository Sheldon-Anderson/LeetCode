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
	vector<string> ans;
	stringstream stream;
	int num;
	string str;
	TreeNode *R;
	
	void DFS(TreeNode* root, string res){
		if(!root){
			return;
		}
		stream << root->val;
		stream >> str;
		stream.clear();
		if(root == R){
			res += str;
		}
		else if(root != R){
			res += ("->" + str);
		}
		if(!root->left && !root->right){
			ans.push_back(res);
			return;
		}
		DFS(root->left, res);
		DFS(root->right, res);
	}

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root){
			return vector<string>();
		}
		R = root;
		DFS(root, "");
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	root->right = new TreeNode(3);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(7);
	vector<string> ans = sol.binaryTreePaths(root);
	// output
	for(string val: ans){
		cout << val << endl;
	}
	return 0;
}
