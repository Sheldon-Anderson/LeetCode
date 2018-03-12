#include<bits/stdc++.h>
using namespace std;

// DFS + memory (dynamic programming)
class Solution {
private: 
	vector<string> ans;
	// end -> starts
	map<int, set<int>> path;
	
	void DFS(string s, string res, int end){
		if(end == -1){
			res = res.substr(0, res.length() - 1);
			ans.push_back(res);
			return;
		}
		set<int> ss = path[end];
		for(auto its = ss.begin(); its != ss.end(); its++){
			int start = *its;	
			DFS(s, s.substr(start, end - start + 1) + " " + res, start - 1);
		}
	}

public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
		int n = wordDict.size();
		// clear
		ans.clear();
		path.clear();
		if(len == 0 || n == 0){
			return ans;
		}
		// create and init
		set<string> wordSet(wordDict.begin(), wordDict.end());
		bool *dp = new bool[len];
		memset(dp, false, sizeof(bool) * len);
		// dp
		for(int i = 0; i <= len - 1; i++){
			if(wordSet.count(s.substr(0, i + 1))){
				dp[i] = true;
				path[i].insert(0);
			}
			for(int j = 0; j <= i - 1; j++){
				if(dp[j] && wordSet.count(s.substr(j + 1, i - j))){
					dp[i] = true;
					path[i].insert(j + 1);
				}
			}
		}
		// check
		if(!dp[len - 1]){
			return ans;
		}
		// debug
		// for(auto &p: path){
			// for(auto its = p.second.begin(); its != p.second.end(); its++){
				// cout << "end: " << p.first << ", start: " << *its << endl;
			// }
		// }
		DFS(s, "", len - 1);
		return ans;
    }
};

int main(){
	Solution sol;
	string s = "aaaaaaa";	// "catsanddog";
	vector<string> wordDict = {"aaaa", "aa", "a"};	// {"cat", "cats", "and", "sand", "dog"};
	vector<string> ans = sol.wordBreak(s, wordDict);
	// console output
	for(string val: ans){
		cout << val << endl;
	}
	return 0;
}
