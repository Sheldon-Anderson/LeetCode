#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

/*
// Accepted
// stack
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        if(!root){
			return -1;
		}
		stack<TreeNode*> st;
		TreeNode *p = root;
		int count = 0, ans = -1;
		while(p || !st.empty()){
			if(p){
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				st.pop();
				if(++count == k){
					ans = p->val;
					break;
				}
				p = p->right;
			}
		}
		return ans;
    }
};
*/

// DFS
class Solution {
private: 
	// count the nodes of the tree
	int countNodes(TreeNode *root){
		if(!root){
			return 0;
		}
		return 1 + countNodes(root->left) + countNodes(root->right);
	}

public:
    int kthSmallest(TreeNode* root, int k) {
		if(!root){
			return -1;
		}
		int count_left = countNodes(root->left);
		int ans = -1;
		if(count_left + 1 == k){
			ans = root->val;
		}
		else if(count_left + 1 < k){
			ans = kthSmallest(root->right, k - count_left - 1);
		}
		else if(count_left + 1 > k){
			ans = kthSmallest(root->left, k);
		}
		return ans;
	}
};

int main(){
	Solution sol;
	TreeNode *T = new TreeNode(4);
	T->left = new TreeNode(2);
	T->left->left = new TreeNode(1);
	T->left->right = new TreeNode(3);
	T->right = new TreeNode(6);
	T->right->left = new TreeNode(5);
	T->right->right = new TreeNode(7);
	int k;
	while(cin >> k){
		cout << "ans: " << sol.kthSmallest(T, k) << endl;
	}
	return 0;
}
