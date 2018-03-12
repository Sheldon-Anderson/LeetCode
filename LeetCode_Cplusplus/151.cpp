#include<bits/stdc++.h>
using namespace std;

// string (istringstream) + stack
class Solution {
public:
    void reverseWords(string &s) {
        istringstream iss(s);
		s = "";
		string str = "";
		stack<string> st;
		while(getline(iss, str, ' ')){
			if(str != ""){
				st.push(str);
			}
		}
		while(!st.empty()){
			s += (st.top() + " ");
			st.pop();
		}
		s = s.substr(0, s.length() - 1);
    }
};

int main(){
	Solution sol;
	string s;
	while(getline(cin, s)){
		// debug
		cout << "s: " << s << endl;		
		sol.reverseWords(s);
		// debug
		cout << "s: " << s << endl;
	}
	return 0;
}
