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

// mergeSort
class Solution {
private: 
	ListNode* merge(ListNode *left, ListNode *right){
		if(!left){
			return right;
		}
		if(!right){
			return left;
		}
		ListNode *p = left, *q = right, *pre;
		while(p && q){
			if(p->val < q->val){
				while(p->next && p->next->val <= q->val){
					p = p->next;
				}
				pre = p;
				p = pre->next;
				pre->next = q;
			}
			else{
				while(q->next && p->val >= q->next->val){
					q = q->next;
				}
				pre = q;
				q = pre->next;
				pre->next = p;
			}
		}
		if(left->val < right->val){
			return left;
		}
		return right;
	}

public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next){
			return head;
		}
		int n = 0;
		ListNode *p = head, *pre = head;
		while(p){
			n++;
			p = p->next;
		}
		for(int i = 1; i <= (n - 1) / 2; i++){
			pre = pre->next;
		}
		p = pre->next;
		pre->next = NULL;
		// merge sort
		head = sortList(head);
		p = sortList(p);
		// merge
		return merge(head, p);
    }
};

int main(){
	Solution sol;
	ListNode* head = new ListNode(6);
	head->next = new ListNode(5);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(4);
	// out 1
	output(head);
	ListNode *ans = sol.sortList(head);
	// out 2
	output(ans);
	return 0;
}
