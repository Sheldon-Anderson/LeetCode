#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

void output(ListNode *root){
	ListNode *p = root;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

// head insert method
class Solution {
public:
    void reorderList(ListNode* head) {
        if(!head || !head->next){
			return;
		}
		ListNode *s = head, *pre = head, *p = head, *q;
		int n = 0;
		while(p){
			n++;
			p = p->next;
		}
		for(int i = 1; i <= n / 2 - 1; i++){
			s = s->next;
		}
		pre = s->next;
		p = pre;
		s->next = NULL;
		// head insert method
		while(pre){
			p = pre->next;
			pre->next = s->next;
			s->next = pre;
			pre = p;
		}
		pre = s;
		s = s->next;
		pre->next = NULL;
		// join
		pre = p = head;
		q = s;
		bool flag = true;
		while(p && q){
			if(flag){
				p = pre->next;
				pre->next = q;
				pre = q;
			}
			else{
				q = pre->next;
				pre->next = p;
				pre = p;
			}
			flag = !flag;
		}
    }
};

int main(){
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	// head->next->next->next->next->next->next->next = new ListNode(8);	
	// output 1
	output(head);
	sol.reorderList(head);
	// output 2
	output(head);
	return 0;
}
