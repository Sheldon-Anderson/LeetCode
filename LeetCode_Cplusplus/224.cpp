#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
	// '+', '-', '(', ')', '#'
	int cmp[5][5] = {
		{1, 1, -1, 1, 1},
		{1, 1, -1, 1, 1},
		{-1, -1, -1, 0, -2},
		{1, 1, -2, 1, 1},
		{-1, -1, -1, -2, 0}
	};

	map<char, int> m;
	
public:
    int calculate(string s) {
        int n = s.length();
		if(n == 0){
			return -1;
		}
		// init
		s += "#";
		m['+'] = 0;
		m['-'] = 1;
		m['('] = 2;
		m[')'] = 3;
		m['#'] = 4;
		stack<char> OPTR;
		stack<int> OPND;
		OPTR.push('#');
		int num = 0, i = 0;
		while(s[i] != '#' || OPTR.top() != '#'){
			if(s[i] >= '0' && s[i] <= '9'){
				while(i <= n - 1 && s[i] >= '0' && s[i] <= '9'){
					num = num * 10 + (s[i] - '0');
					i++;
				}
				OPND.push(num);
				num = 0;
			}
			else if(s[i] == ' '){
				i++;
			}
			// '+', '-', '(', ')', '#'
			else{
				char c = OPTR.top();
				int check = cmp[m[c]][m[s[i]]];
				switch(check){
					case -2: break;
					case -1: OPTR.push(s[i++]); break;
					case 0: OPTR.pop(); i++; break;
					case 1: 
						OPTR.pop();
						int b = OPND.top();
						OPND.pop();
						int a = OPND.top();
						OPND.pop();
						int result;
						if(c == '+'){
							result = a + b;
						}
						else if(c == '-'){
							result = a - b;
						}
						OPND.push(result);
						break;
				}
			}
		}
		return OPND.top();
    }
};

int main(){
	Solution sol;
	string s;
	while(getline(cin, s)){
		cout << "ans: " << sol.calculate(s) << endl;
	}
	return 0;
}
