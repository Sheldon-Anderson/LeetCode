#include<bits/stdc++.h>
using namespace std;

struct UndirectedGraphNode{
	int label;
	vector<UndirectedGraphNode *> neighbors;
	UndirectedGraphNode(int x): label(x){}
};

// map + DFS
class Solution {
private: 
	map<UndirectedGraphNode* , UndirectedGraphNode*> m;

public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node){
			return node;
		}
        if(!m.count(node)){
			UndirectedGraphNode *newNode = new UndirectedGraphNode(node->label);
			m[node] = newNode;
			for(UndirectedGraphNode* p: node->neighbors){
				newNode->neighbors.push_back(cloneGraph(p));
			}
		}
		return m[node];
    }
};

set<UndirectedGraphNode*> s;
void output(UndirectedGraphNode* node){
	if(s.count(node)){
		cout << "NULL" << endl;
		return;
	}
	cout << node->label << " ";
	s.insert(node);
	for(UndirectedGraphNode *p: node->neighbors){
		output(p);
	}
}

int main(){
	Solution sol;
	UndirectedGraphNode *n0 = new UndirectedGraphNode(0);
	UndirectedGraphNode *n1 = new UndirectedGraphNode(1);
	UndirectedGraphNode *n2 = new UndirectedGraphNode(2);
	n0->neighbors.push_back(n1);
	n0->neighbors.push_back(n2);
	n1->neighbors.push_back(n0);
	n1->neighbors.push_back(n2);	
	n2->neighbors.push_back(n0);
	n2->neighbors.push_back(n1);	
	n2->neighbors.push_back(n2);
	// console output 1
	output(n0);
	UndirectedGraphNode *ans = sol.cloneGraph(n0);
	// console output 2
	output(ans);
	return 0;
}
