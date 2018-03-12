#include<bits/stdc++.h>
using namespace std;

struct TreeLinkNode{
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x): val(x), left(NULL), right(NULL), next(NULL){}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(!root){
			return;
		}
		queue<TreeLinkNode* > pre, cur;
		pre.push(root);
		while(!pre.empty()){
			TreeLinkNode *p = NULL, *q;
			while(!pre.empty()){
				q = pre.front();
				pre.pop();
				if(p){
					p->next = q;
				}
				if(q->left){
					cur.push(q->left);
				}
				if(q->right){
					cur.push(q->right);
				}
				p = q;
			}
			swap(pre, cur);
		}
    }
};

void output(TreeLinkNode *root){
	if(!root){
		return;
	}
	cout << root->val << " ";
	output(root->left);
	output(root->right);
}

void pre_output(TreeLinkNode *root){
	if(!root){
		return;
	}
	if(root->next){
		cout << "cur: " << root->val << ", next: " << root->next->val << endl;
	}
	else{
		cout << "cur: " << root->val << ", next: NULL" << endl;
	}
	pre_output(root->left);
	pre_output(root->right);
}

int main(){
	Solution sol;
	TreeLinkNode *root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->left->left = new TreeLinkNode(4);
	root->left->right = new TreeLinkNode(5);
	root->right = new TreeLinkNode(3);
	root->right->left = new TreeLinkNode(6);	
	root->right->right = new TreeLinkNode(7);
	// console output 1
	output(root);
	cout << endl;
	sol.connect(root);
	// console output 2
	pre_output(root);
	return 0;
}
