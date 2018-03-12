#include<bits/stdc++.h>
using namespace std;

/*
// two stacks
// Accepted
class MinStack {
private: 	
	int minVal;
	stack<int> s1, s2;

public:
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        s1.push(x);
		minVal = min(minVal, x);
		s2.push(minVal);
    }
    
    void pop() {
        if(!s1.empty()){
			s1.pop();
			s2.pop();
			if(s1.empty()){
				minVal = INT_MAX;
			}
			else{
				minVal = s2.top();
			}
		}
    }
    
    int top() {
		if(!s1.empty()){
			return s1.top();
		}
        return -1;
    }
    
    int getMin() {
		if(!s2.empty()){
			return minVal;
		}
        return -1;
    }
};
*/

#define LL long long

// one stack
class MinStack {
private: 
	// save the current min value
	LL minVal;
	// save the delta between current value and the previous min value
	stack<LL> st;

public:
    /** initialize your data structure here. */
    MinStack() {
        minVal = INT_MAX;
    }
    
    void push(int x) {
        if(st.empty()){
			st.push(0L);
			minVal = x;
		}
		else{
			st.push(x - minVal);
			if(x < minVal){
				minVal = x;
			}
		}
    }
    
    void pop() {
        if(st.empty()){
			return;
		}
		LL top = st.top();
		st.pop();
		if(top < 0){
			minVal -= top;
		}
    }
    
    int top() {
        if(st.empty()){
			return -1;
		}
		LL top = st.top();
		if(top > 0){
			return (int)(minVal + top);
		}
		else{
			return (int)minVal;
		}
    }
    
    int getMin() {
        return (int)minVal;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(){
	MinStack ms;
	// push 1
	ms.push(3);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	ms.push(1);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	ms.push(4);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	// pop
	ms.pop();
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	ms.pop();
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;	
	// push 2
	ms.push(2);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	ms.push(5);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	ms.push(9);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	ms.push(6);
	cout << "top: " << ms.top() << endl;
	cout << "min: " << ms.getMin() << endl;
	return 0;
}
