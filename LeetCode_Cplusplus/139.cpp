#include<bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.length();
		int n = wordDict.size();
		if(!len || !n){
			return false;
		}
		// create
		set<string> wordSet(wordDict.begin(), wordDict.end());
		bool *dp = new bool[len];
		memset(dp, false, sizeof(bool) * len);
		// dp
		for(int i = 0; i <= len - 1; i++){
			if(wordSet.count(s.substr(0, i + 1))){
				dp[i] = true;
			}
			else{
				for(int j = 0; j <= i - 1; j++){
					if(dp[j] && wordSet.count(s.substr(j + 1, i - j))){
						dp[i] = true;
						break;
					}
				}				
			}
		}
		// get answer
		return dp[len - 1];
    }
};

int main(){
	Solution sol;
	string s = "leetcode";
	vector<string> wordDict = {"leet", "code"};
	cout << "ans: " << sol.wordBreak(s, wordDict) << endl;
	return 0;
}
