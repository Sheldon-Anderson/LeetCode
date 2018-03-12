#include <bits/stdc++.h>
using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
public: 
	// Return true if this NestedInteger holds a single integer, rather than a nested list.
	bool isInteger() const;
	// Return the single integer that this NestedInteger holds, if it holds a single integer
	// The result is undefined if this NestedInteger holds a nested list
	int getInteger() const;
	// Return the nested list that this NestedInteger holds, if it holds a nested list
	// The result is undefined if this NestedInteger holds a single integer
	const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private: 
	queue<int> q;
	
	void DFS(vector<NestedInteger> &nestedList){
		for(NestedInteger p: nestedList){
			if(p.isInteger()){
				q.push(p.getInteger());
			}
			else{
				DFS(p.getList());
			}
		}
	}

public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        DFS(nestedList);
    }

    int next() {
        int ans = -1;
		if(q.size()){
			ans = q.front();
			q.pop();
		}
		return ans;
    }

    bool hasNext() {
        return q.size();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, char** argv){
	// vector<NestedInteger> nestedList = {{1, 1}, 2, {1, 1}};
	// NestedIterator nt(nestedList);
	// while(nt.hasNext()){
		// cout << nt.next() << " ";
	// }
	// cout << endl;
	return 0;
}
