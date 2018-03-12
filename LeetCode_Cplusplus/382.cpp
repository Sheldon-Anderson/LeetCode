#include <bits/stdc++.h>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

// rand()
class Solution {
private: 
	int n;
	ListNode *H;
	
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        n = 0;
		H = head;
		ListNode *p = H;
		while(p){
			n++;
			p = p->next;
		}
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int R = rand() % n;
		ListNode *p = H;
		while(R--){
			p = p->next;
		}
		return p->val;
    }
};

int main(int argc, char** argv){
	ListNode *H = new ListNode(1);
	H->next = new ListNode(2);
	H->next->next = new ListNode(3);
	H->next->next->next = new ListNode(4);
	H->next->next->next->next = new ListNode(5);
	Solution sol(H);
	int N = 10;
	while(N--){
		cout << "random: " << sol.getRandom() << endl;
	}
	return 0;
}
