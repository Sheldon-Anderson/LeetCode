#include <bits/stdc++.h>
using namespace std;

// DFS + stack
class Solution {
private: 
	vector<string> ans;
	
	void DFS(string s, string res, int n, int pos, int cnt_left, int cnt_right, int cnt_remove, int cnt){
		if(pos == n){
			if(cnt_left == cnt_right && cnt == cnt_remove){
				if(find(ans.begin(), ans.end(), res) == ans.end()){
					ans.push_back(res);
				}
			}
			return;
		}
		if(s[pos] == '('){
			DFS(s, res + "(", n, pos + 1, cnt_left + 1, cnt_right, cnt_remove, cnt);
			DFS(s, res, n, pos + 1, cnt_left, cnt_right, cnt_remove, cnt + 1);
		}
		else if(s[pos] == ')'){
			if(cnt_left > cnt_right){
				DFS(s, res + ")", n, pos + 1, cnt_left, cnt_right + 1, cnt_remove, cnt);
			}
			DFS(s, res, n, pos + 1, cnt_left, cnt_right, cnt_remove, cnt + 1);
		}
		else{
			DFS(s, res + s[pos], n, pos + 1, cnt_left, cnt_right, cnt_remove, cnt);
		}
	}

public:
    vector<string> removeInvalidParentheses(string s) {
		ans.clear();
        int n = s.length();
		if(n == 0){
			return vector<string>{""};
		}
		stack<char> st;
		int cnt_remove = 0;
		for(int i = 0; i <= n - 1; i++){
			if(s[i] == '('){
				st.push('(');
			}
			else if(s[i] == ')'){
				if(st.empty()){
					cnt_remove++;
				}
				else{
					st.pop();
				}
			}
		}
		while(!st.empty()){
			cnt_remove++;
			st.pop();
		}
		DFS(s, "", n, 0, 0, 0, cnt_remove, 0);
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		vector<string> ans = sol.removeInvalidParentheses(s);
		// console output
		for(string val: ans){
			cout << val << endl;
		}
	}
	return 0;
}
