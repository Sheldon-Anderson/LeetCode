#include<bits/stdc++.h>
using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(!head || !head->next){
			return true;
		}
		ListNode *pre = head, *p = head, *h = new ListNode(-1), *s = h;
		// count
		int n = 0;
		while(p){
			n++;
			p = p->next;
		}
		// head insert method
		for(int i = 1; i <= n / 2; i++){
			p = pre->next;
			pre->next = s->next;
			s->next = pre;
			pre = p;
		}
		if(n & 1){
			p = p->next;
		}
		s = s->next;
		while(p && s){
			if(p->val != s->val){
				return false;
			}
			p = p->next;
			s = s->next;
		}
		return true;
    }
};

int main(int argc, char* argv[]){
	Solution sol;
	ListNode *head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(1);
	// head->next->next->next->next = new ListNode(1);
	cout << "ans: " << sol.isPalindrome(head) << endl;
	return 0;
}
