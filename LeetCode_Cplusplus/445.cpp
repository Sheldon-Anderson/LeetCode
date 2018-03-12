#include<bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};


void output(ListNode *H){
	ListNode *p = H;
	while(p){
		cout << p->val << " ";
		p = p->next;
	}
	cout << endl;
}

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int n1 = 0, n2 = 0;
		ListNode *p = l1, *q = l2;
		while(p){
			n1++;
			p = p->next;
		}
		while(q){
			n2++;
			q = q->next;
		}
		// head insert for l3
		ListNode *l3 = new ListNode(-1), *r = l3, *t;
		p = l1;
		q = l2;
		if(n1 > n2){
			for(int i = 1; i <= n1 - n2; i++){
				t = new ListNode(p->val);
				t->next = r->next;
				r->next = t;
				p = p->next;
			}
		}
		else if(n1 < n2){
			for(int i = 1; i <= n2 - n1; i++){
				t = new ListNode(q->val);
				t->next = r->next;
				r->next = t;
				q = q->next;
			}
		}
		while(p){
			t = new ListNode(p->val + q->val);
			t->next = r->next;
			r->next = t;
			p = p->next;
			q = q->next;
		}
		// debug
		// output(l3);
		int digit = 0, carry = 0;
		r = l3;
		while(r->next){
			digit = (r->next->val + carry) % 10;
			carry = (r->next->val + carry) / 10;
			r->next->val = digit;
			r = r->next;
		}
		if(carry){
			r->next = new ListNode(1);
		}
		// head insert: reverse ans
		r = l3->next;
		ListNode *l4 = new ListNode(-1), *s = l4, *nxt = r->next;
		while(r){
			r->next = s->next;
			s->next = r;
			r = nxt;
			if(nxt){
				nxt = nxt->next;
			}
		}
		// get answer
		return l4->next;
    }
};

int main(int argc, char** argv){
	Solution sol;
	ListNode *l1, *l2;
	l1 = new ListNode(9);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(9);
	l1->next->next->next = new ListNode(9);
	l2 = new ListNode(1);
	l2->next = new ListNode(2);
	l2->next->next = new ListNode(3);
	// output 1
	output(l1);
	output(l2);
	ListNode* ans = sol.addTwoNumbers(l1, l2);
	// output 2
	output(ans);
	return 0;
}
