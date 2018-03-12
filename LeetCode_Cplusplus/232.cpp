#include<bits/stdc++.h>
using namespace std;

class MyQueue {
private: 
	stack<int> s1, s2;

public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
		int ans = -1;
		if(s1.empty()){
			return ans;
		}
		while(!s1.empty()){
			int top = s1.top();
			s1.pop();
			s2.push(top);
		}
		ans = s2.top();
		s2.pop();
		while(!s2.empty()){
			int top = s2.top();
			s2.pop();
			s1.push(top);
		}
		return ans;
    }
    
    /** Get the front element. */
    int peek() {
		int ans = -1;
		if(s1.empty()){
			return ans;
		}
		while(!s1.empty()){
			int top = s1.top();
			s1.pop();
			s2.push(top);
		}
		ans = s2.top();
		while(!s2.empty()){
			int top = s2.top();
			s2.pop();
			s1.push(top);
		}
		return ans;        
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue obj = new MyQueue();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.peek();
 * bool param_4 = obj.empty();
 */

int main(int argc, char* argv[]){
	MyQueue mq;
	// push
	mq.push(1);
	mq.push(2);
	mq.push(3);
	mq.push(4);
	mq.push(5);
	// peek and pop
	while(!mq.empty()){
		cout << mq.peek() << endl;
		mq.pop();
	}
	return 0;
}
