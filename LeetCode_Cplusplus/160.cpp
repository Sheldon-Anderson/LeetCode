#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB){
			return NULL;
		}
		ListNode *p = headA, *q = headB;
		int n1 = 0, n2 = 0;
		while(p){
			n1++;
			p = p->next;
		}
		while(q){
			n2++;
			q = q->next;
		}
		p = headA;
		q = headB;
		if(n1 - n2 > 0){
			for(int i = 1; i <= n1 - n2; i++){
				p = p->next;
			}
		}
		else if(n1 - n2 < 0){
			for(int i = 1; i <= n2 - n1; i++){
				q = q->next;
			}
		}
		while(p && q && p != q){
			p = p->next;
			q = q->next;
		}
		if(!p || !q){
			return NULL;
		}
		return p;
    }
};

int main(){
	Solution sol;
	ListNode *headA = new ListNode(2);
	headA->next = new ListNode(3);
	headA->next->next = new ListNode(4);
	headA->next->next->next = new ListNode(5);
	headA->next->next->next->next = new ListNode(6);
	ListNode *headB = new ListNode(10);
	headB->next = new ListNode(20);
	headB->next->next = new ListNode(30);
	headB->next->next->next = headA->next->next;
	ListNode *ans = sol.getIntersectionNode(headA, headB);
	// console output
	cout << "ans: " << ans->val << endl;
	return 0;
}
