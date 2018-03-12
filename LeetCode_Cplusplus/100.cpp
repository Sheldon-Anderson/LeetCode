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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q){
			return true;
		}
		if(!p || !q){
			return false;
		}
		return (p->val == q->val) && (isSameTree(p->left, q->left)) && (isSameTree(p->right, q->right));
    }
};

int main(){
	Solution sol;
	// tree 1
	TreeNode* r1 = new TreeNode(3);
	r1->left = new TreeNode(2);
	r1->right = new TreeNode(4);
	// tree 2
	TreeNode* r2 = new TreeNode(3);
	r2->left = new TreeNode(2);
	r2->right = new TreeNode(1);
	cout << "ans: " << sol.isSameTree(r1, r2) << endl;
	return 0;
}
