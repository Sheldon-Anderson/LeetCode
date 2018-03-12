#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(!head){
			return head;
		}
		ListNode *h = new ListNode(-1);
		h->next = head;
		ListNode *p = h, *q;
		while(p->next){
			if(p->next->val == val){
				q = p->next;
				p->next = q->next;
				free(q);
			}
			else{
				p = p->next;
			}
		}
		return h->next;
    }
};

void output(ListNode *H){
	ListNode *p = H;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

int main(){
	Solution sol;
	ListNode* head = new ListNode(6);
	head->next = new ListNode(2);
	head->next->next = new ListNode(6);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(4);
	head->next->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next->next = new ListNode(6);
	int val = 6;
	// out 1
	output(head);
	ListNode *ans = sol.removeElements(head, val);
	// out 2
	output(ans);
	return 0;
}
