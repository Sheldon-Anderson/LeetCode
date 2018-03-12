#include<bits/stdc++.h>
using namespace std;

// stack
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
		if(n == 0){
			return 0;
		}
		stack<int> st;
		stringstream stream;
		for(int i = 0; i <= n - 1; i++){
			int a, b, c;
			if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
				b = st.top();
				st.pop();
				a = st.top();
				st.pop();
				switch(tokens[i][0]){
					case '+': c = a + b; break;
					case '-': c = a - b; break;
					case '*': c = a * b; break;
					case '/': c = a / b; break;
				}
				st.push(c);
			}
			else{
				stream << tokens[i];
				stream >> c;
				stream.clear();
				st.push(c);
			}
		}
		return st.top();
    }
};

int main(){
	Solution sol;
	vector<string> tokens = {"4", "13", "5", "/", "+"};	// {"2", "1", "+", "3", "*"};
	cout << "ans: " << sol.evalRPN(tokens) << endl;
	return 0;
}
