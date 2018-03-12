#include<bits/stdc++.h>
using namespace std;

struct RandomListNode{
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x): label(x), next(NULL), random(NULL){}
};

class Solution {
private: 
	map<RandomListNode*, RandomListNode*> m;

public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(!head){
			return head;
		}
		if(!m.count(head)){
			RandomListNode *newNode = new RandomListNode(head->label);
			m[head] = newNode;
			if(head->next){
				newNode->next = copyRandomList(head->next);
			}
			if(head->random){
				newNode->random = copyRandomList(head->random);
			}
		}
		return m[head];
    }
};

void output(RandomListNode *root){
	RandomListNode *p = root;
	while(p->next){
		cout << "p: " << p->label << ", next: " << p->next->label << ", random: " << p->random->label << endl;
		p = p->next;
	}
	cout << "p: " << p->label << endl;
	cout << endl;
}

int main(){
	Solution sol;
	RandomListNode *n0 = new RandomListNode(0);
	RandomListNode *n1 = n0->next = new RandomListNode(1);
	RandomListNode *n2 = n1->next = new RandomListNode(2);
	RandomListNode *n3 = n2->next = new RandomListNode(3);
	RandomListNode *n4 = n3->next = new RandomListNode(4);
	RandomListNode *n5 = n4->next = new RandomListNode(5);
	n0->random = n2;
	n1->random = n3;
	n2->random = n4;
	n3->random = n5;
	n4->random = n0;
	n5->random = n1;
	// output 1
	output(n0);
	RandomListNode *ans = sol.copyRandomList(n0);
	// output 2
	output(ans);
	return 0;
}
