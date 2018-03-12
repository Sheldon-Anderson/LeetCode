#include <bits/stdc++.h>
using namespace std;

/*
// DFS + greedy
// Accepted
class Solution {
private: 
	bool *visited;
	string ans;
	
	void DFS(string s, string res, int n, int start){
		if(ans != ""){
			return;
		}
		if(start == n){
			ans = res;
			return;
		}
		// count
		int *cnt = new int[26];
		memset(cnt, 0, sizeof(int) * 26);
		for(int i = start; i <= n - 1; i++){
			cnt[s[i] - 'a']++;
		}
		int pos = start;
		// find the first unvisited char
		while(visited[s[pos] - 'a']){
			pos++;
		}
		for(int i = pos; i <= n - 1; i++){
			if(visited[s[i] - 'a']){
				continue;
			}
			if(s[i] < s[pos]){
				pos = i;
			}
			if(!(--cnt[s[i] - 'a'])){
				break;
			}
		}
		if(pos <= n - 1){
			visited[s[pos] - 'a'] = true;
			DFS(s, res + s[pos], n, pos + 1);
			visited[s[pos] - 'a'] = false;
		}
		else{
			DFS(s, res, n, n);
		}
	}

public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
		if(n <= 1){
			return s;
		}
		// create and init
		visited = new bool[26];
		memset(visited, false,sizeof(bool) * 26);
		ans = "";
		DFS(s, "", n, 0);
		return ans;
    }
};
*/

// stack + greedy
class Solution{
public:
    string removeDuplicateLetters(string s) {
		int n = s.length();
		if(n <= 1){
			return s;
		}
		// create and init
		bool *visited = new bool[26];
		int *cnt = new int[26];
		memset(visited, false, sizeof(bool) * 26);
		memset(cnt, 0, sizeof(int) * 26);
		stack<char> st;
		// count
		for(int i = 0; i <= n - 1; i++){
			cnt[s[i] - 'a']++;
		}
		// stack manipulation
		for(int i = 0; i <= n - 1; i++){
			if(!visited[s[i] - 'a']){
				while(!st.empty()){
					char c = st.top();
					if(s[i] < c && visited[c - 'a'] && !visited[s[i] - 'a'] && cnt[c - 'a']){
						st.pop();
						visited[c - 'a'] = false;
					}
					else{
						break;
					}
				}
				st.push(s[i]);
				visited[s[i] - 'a'] = true;
			}
			cnt[s[i] - 'a']--;
		}
		// get answer
		string ans = "";
		while(!st.empty()){
			char c = st.top();
			st.pop();
			ans += c;
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.removeDuplicateLetters(s) << endl;
	}
	return 0;
}
