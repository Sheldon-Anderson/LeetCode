#include <bits/stdc++.h>

using namespace std;

// This is the interface that allows for creating nested lists.
// You should not implement it, or speculate about its implementation
class NestedInteger {
  public:
    // Constructor initializes an empty nested list.
    NestedInteger();

    // Constructor initializes a single integer.
    NestedInteger(int value);

    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Set this NestedInteger to hold a single integer.
    void setInteger(int value);

    // Set this NestedInteger to hold a nested list and adds a nested integer to it.
    void add(const NestedInteger &ni);

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

// stack
class Solution {
public:
    NestedInteger deserialize(string s) {
        NestedInteger ans;
		stringstream stream;
		int n = s.length();
		// Exceptional Case: 
		if(!n){
			return ans;
		}
		// only one integer
		if(s[0] != '['){
			int digit;
			stream << s;
			stream >> digit;
			stream.clear();
			ans.setInteger(digit);
		}
		else{
			bool flag_num = false, flag_minus = false;
			int num = 0;
			stack<NestedInteger> st;
			for(int i = 0; i <= n - 1; i++){
				if(s[i] == '['){
					if(i != 0){
						st.push(ans);
					}
					ans = NestedInteger();
				}
				else if(s[i] == ']' || s[i] == ','){
					if(flag_num){
						if(flag_minus){
							num = -num;
						}
						ans.add(num);
					}
					if(s[i] == ']' && !st.empty()){
						st.top().add(ans);
						ans = st.top();
						st.pop();
					}
					num = 0;
					flag_num = flag_minus = false;
				}
				else if(s[i] == '-'){
					flag_minus = true;
				}
				else if(s[i] >= '0' && s[i] <= '9'){
					num = 10 * num + (s[i] - '0');
					flag_num = true;
				}
			}
		}
		return ans;
    }
};

int main(int argc, char*argv){

	return 0;
}
