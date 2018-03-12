#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

struct TreeNode{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x): val(x), left(NULL), right(NULL){}
};

class Solution {
private: 
	TreeNode *DFS(ListNode *head, int n){
		if(n == 0){
			return NULL;
		}
		if(n == 1){
			return new TreeNode(head->val);
		}
		int cnt_left = (n - 1) / 2;
		int cnt_right = n - 1 - cnt_left;
		ListNode *p = head;
		for(int i = 1; i <= cnt_left; i++){
			p = p->next;
		}
		TreeNode *root = new TreeNode(p->val);
		root->left = DFS(head, cnt_left);
		root->right = DFS(p->next, cnt_right);
		return root;
	}

public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head){
			return NULL;
		}
		ListNode *p = head;
		int n = 0;
		while(p){
			n++;
			p = p->next;
		}
		return DFS(head, n);
    }
};

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
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	head->next->next->next->next->next->next->next = new ListNode(8);
	TreeNode *ans = sol.sortedListToBST(head);
	// console output
	in_output(ans);
	cout << endl;
	return 0;
}
