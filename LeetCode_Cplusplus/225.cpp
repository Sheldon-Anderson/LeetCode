#include<bits/stdc++.h>
using namespace std;

// queue + stack
class MyStack {
private: 
	queue<int> q1, q2;

public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if(q1.empty() && q2.empty()){
			q1.push(x);
		}
		else if(!q1.empty() && q2.empty()){
			q1.push(x);
		}
		else if(q1.empty() && !q2.empty()){
			q2.push(x);
		}
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = -1;
		if(q1.empty() && q2.empty()){
			return ans;
		}
		else if(!q1.empty() && q2.empty()){
			int size = q1.size();
			for(int i = 1; i <= size - 1; i++){
				ans = q1.front();
				q1.pop();
				q2.push(ans);
			}
			ans = q1.front();
			q1.pop();
		}
		else if(q1.empty() && !q2.empty()){
			int size = q2.size();
			for(int i = 1; i <= size - 1; i++){
				ans = q2.front();
				q2.pop();
				q1.push(ans);
			}
			ans = q2.front();
			q2.pop();
		}
		return ans;        
    }
    
    /** Get the top element. */
    int top() {
        int ans = -1;
		if(q1.empty() && q2.empty()){
			return ans;
		}
		else if(!q1.empty() && q2.empty()){
			while(!q1.empty()){
				ans = q1.front();
				q1.pop();
				q2.push(ans);
			}
		}
		else if(q1.empty() && !q2.empty()){
			while(!q2.empty()){
				ans = q2.front();
				q2.pop();
				q1.push(ans);
			}
		}
		return ans;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack obj = new MyStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * bool param_4 = obj.empty();
 */

int main(){
	MyStack ms;
	ms.push(1);
	ms.push(2);
	ms.push(3);
	ms.push(4);
	ms.push(5);
	while(!ms.empty()){
		// cout << ms.top() << endl;
		// ms.pop();
		cout << ms.pop() << endl;
	}
	return 0;
}
