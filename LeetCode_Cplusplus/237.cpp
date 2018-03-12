#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;
		node->next = node->next->next;
    }
};

void output(ListNode *T){
	ListNode *p = T;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(int argc, char* argv[]){
	ListNode *root = new ListNode(1);
	root->next = new ListNode(2);
	root->next->next = new ListNode(3);
	root->next->next->next = new ListNode(4);
	root->next->next->next->next = new ListNode(5);
	// out 1
	output(root);
	Solution sol;
	sol.deleteNode(root->next);
	// out 2
	output(root);
	return 0;
}
