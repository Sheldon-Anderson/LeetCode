#include <bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head || !head->next || !head->next->next){
			return head;
		}
		ListNode *h1 = new ListNode(-1), *p = h1;
		ListNode *h2 = new ListNode(-1), *q = h2;
		ListNode *cur = head, *nxt;
		bool flag = true;
		while(cur){
			nxt = cur->next;
			if(flag){
				p->next = cur;
				p = p->next;
			}
			else{
				q->next = cur;
				q = q->next;
			}
			flag = !flag;
			cur = nxt;
		}
		q->next = NULL;
		p->next = h2->next;
		return h1->next;
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

int main(int argc, char** argv){
	Solution sol;
	ListNode *H = new ListNode(1);
	H->next = new ListNode(2);
	H->next->next = new ListNode(3);
	H->next->next->next = new ListNode(4);
	H->next->next->next->next = new ListNode(5);
	H->next->next->next->next->next = new ListNode(6);
	// out 1
	output(H);
	ListNode *ans = sol.oddEvenList(H);
	// out 2
	output(ans);
	return 0;
}
