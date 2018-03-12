#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
private: 
	vector<vector<string>> ans;
	vector<string> res;

	bool check(string s, int start, int end){
		for(int i = start; i <= (start + end) / 2; i++){
			if(s[i] != s[start + end - i]){
				return false;
			}
		}
		return true;
	}
	
	void DFS(string s, int n, int start){
		if(start == n){
			ans.push_back(res);
			return;
		}
		for(int i = 1; i <= n - start; i++){
			if(check(s, start, start + i - 1)){
				res.push_back(s.substr(start, i));
				DFS(s, n, start + i);
				res.pop_back();
			}
		}
	}

public:
    vector<vector<string>> partition(string s) {
		ans.clear();
		res.clear();
        int n = s.length();
		if(n == 0){
			return ans;
		}
		DFS(s, n, 0);
		return ans;
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		vector<vector<string>> ans = sol.partition(s);
		// console output
		for(auto &p: ans){
			for(string val: p){
				cout << val << " ";
			}
			cout << endl;
		}		
	}
	return 0;
}
