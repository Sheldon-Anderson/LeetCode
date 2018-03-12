#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

/*
// iteratively
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head){
			return head;
		}
		ListNode *h = new ListNode(-1);
		ListNode *s = h, *pre = head, *p;
		while(pre){
			p = pre->next;
			pre->next = s->next;
			s->next = pre;
			pre = p;
		}
		return h->next;
    }
};
*/

// recursively
class Solution {
private: 
	void DFS(ListNode *s, ListNode *pre){
		if(!pre){
			return;
		}
		ListNode *p = pre->next;
		pre->next = s->next;
		s->next = pre;
		pre = p;
		DFS(s, pre);
	}

public:
    ListNode* reverseList(ListNode* head) {
		if(!head){
			return head;
		}
		ListNode *h = new ListNode(-1);
		ListNode *s = h, *pre = head;
		DFS(s, pre);
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
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	// out 1
	output(head);
	ListNode *ans = sol.reverseList(head);
	// out 2
	output(ans);
	return 0;
}
