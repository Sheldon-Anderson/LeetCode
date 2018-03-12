#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

// two pointers
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head){
			return head; 
		}
		// p moves 1 step per time, q moves 2 steps per time
		ListNode *p = head, *q = head;
		while(p && q){
			p = p->next;
			if(q->next){
				q = q->next->next;
				// if(p && q && p->val == q->val){ will cause a Time Limit Exceeded
				if(p && q && p == q){
					// set p to the head, p and q move 1 step per time, when p and q meet again, return the node that cycle begins
					p = head;
					while(p != q){
						p = p->next;
						q = q->next;
					}
					return p;
				}
			}
			else{
				break;
			}
		}
		return NULL;
    }
};

int main(){
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = head;
	/*
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);
	head->next->next->next->next->next->next = new ListNode(7);
	head->next->next->next->next->next->next->next = new ListNode(8);
	head->next->next->next->next->next->next->next = head->next->next->next;	// 8 -> 4	
	*/
	ListNode *ans = sol.detectCycle(head);
	cout << "ans: " << ans->val << endl;
	return 0;
}
