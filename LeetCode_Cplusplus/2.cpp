#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
private: 
	void add(ListNode *&r, int digit){
		r->next = new ListNode(digit);
		r = r->next;			
	}

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Exceptional Case: 
		if(!l1){
			return l2;
		}
		if(!l2){
			return l1;
		}
		ListNode *p = l1, *q = l2, *l3 = new ListNode(-1), *r = l3;
		int digit = 0, carry = 0;
		while(p && q){
			digit = (p->val + q->val + carry) % 10;
			carry = (p->val + q->val + carry) / 10;
			add(r, digit);
			p = p->next;
			q = q->next;
		}
		while(p){
			digit = (p->val + carry) % 10;
			carry = (p->val + carry) / 10;
			add(r, digit);
			p = p->next;
		}
		while(q){
			digit = (q->val + carry) % 10;
			carry = (q->val + carry) / 10;
			add(r, digit);
			q = q->next;
		}
		if(carry){
			add(r, 1);
		}
		return l3->next;
    }
};

int main(){
	ListNode *l1 = new ListNode(9);
	l1->next = new ListNode(9);
	l1->next->next = new ListNode(9);
	ListNode *l2 = new ListNode(1);
	l2->next = new ListNode(1);
	l2->next->next = new ListNode(1);
	Solution sol;
	ListNode *l3 = sol.addTwoNumbers(l1, l2);
	// console output
	ListNode *r = l3;
	while(r){
		cout << r->val << " ";
		r= r->next;
	}
	cout << endl;
	return 0;
}
