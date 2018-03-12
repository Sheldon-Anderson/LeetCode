#include <bits/stdc++.h>
using namespace std;

// stack
class Solution {
public:
    string decodeString(string s) {
		int n = s.length();
		if(!n){
			return "";
		}
		int digit = 0;
		string str = "";
		// stack: current digit(int), previous str(string)
		stack<pair<int, string>> st;
		for(int i = 0; i <= n - 1; i++){
			if(s[i] >= '0' && s[i] <= '9'){
				digit = 10 * digit + (s[i] - '0');
			}
			else if(s[i] == '['){
				st.push(make_pair(digit, str));
				str = "";
				digit = 0;
			}
			else if(s[i] == ']'){
				pair<int, string> p = st.top();
				st.pop();
				string res = "";
				int cnt = p.first;
				while(cnt--){
					res += str;
				}
				str = p.second + res;
			}
			else{
				str += s[i];
			}
		}
		return str;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.decodeString(s) << endl;
	}
	return 0;
}
