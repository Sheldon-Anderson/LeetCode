#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next){
			return head;
		}
		ListNode *h = new ListNode(-1);
		ListNode *pre = head->next, *p, *s;
		h->next = head;
		head->next = NULL;
		// insert sort
		while(pre){
			s = h;
			p = pre->next;
			while(s->next && s->next->val <= pre->val){
				s = s->next;
			}
			if(!s->next){
				s->next = pre;
				pre->next = NULL;
			}
			else{
				pre->next = s->next;
				s->next = pre;
			}
			pre = p;
		}
		return h->next;
    }
};

void output(ListNode *root){
	if(!root){
		return;
	}
	ListNode *p = root;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(){
	Solution sol;
	ListNode* head = new ListNode(3);
	head->next = new ListNode(1);
	head->next->next = new ListNode(4);
	head->next->next->next = new ListNode(1);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(5);
	// out 1
	output(head);
	ListNode* ans = sol.insertionSortList(head);
	// out 2
	output(ans);
	return 0;
}
