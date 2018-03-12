#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// stack
class BSTIterator {
private: 
	TreeNode *T;
	TreeNode *p;
	stack<TreeNode*> st;
	
public:
    BSTIterator(TreeNode *root) {
        T = root;
		p = T;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return p || !st.empty();
    }

    /** @return the next smallest number */
    int next() {
		int ans = -1;
        while(p || !st.empty()){
			if(p){
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				st.pop();
				ans = p->val;
				p = p->right;
				break;
			}
		}
		return ans;
    }
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
 
int main(){
	TreeNode *root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);
	root->right = new TreeNode(6);
	root->right->left = new TreeNode(5);
	root->right->right = new TreeNode(7);
	BSTIterator bit(root);
	while(bit.hasNext()){
		cout << bit.next() << " ";
	}
	cout << endl;
	return 0;
}
