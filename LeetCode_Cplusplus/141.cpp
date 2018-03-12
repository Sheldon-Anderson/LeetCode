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
    bool hasCycle(ListNode *head) {
        if(!head || !head->next){
			return false;
		}
		ListNode *p = head, *q = head;
		while(p && q){
			p = p->next;
			if(q->next){
				q = q->next->next;
				// if(p && q && p->val == q->val){ also Accepted!
				if(p && q && p == q){
					return true;
				}
			}
			else{
				break;
			}
		}
		return false;
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
	head->next->next->next->next->next->next->next = new ListNode(8);
	head->next->next->next->next->next->next->next = head->next->next->next;	// 8 -> 4
	// console output
	cout << "ans: " << sol.hasCycle(head) << endl;
	return 0;
}
