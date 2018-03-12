#include<bits/stdc++.h>
using namespace std;

/*
	len(s) = n1, len(p) = n2
	dp[n1 + 1][n2 + 1]:
	1. p[j - 1] != '*': 
	   dp[i][j] = (i - 1 >= 0) && dp[i - 1][j - 1] && ((s[i - 1] == p[j - 1]) || (p[j - 1] == '.'))
	2. p[j - 1] == '*': 
	   dp[i][j] = (j - 2 >= 0 && dp[i][j - 2]) || (i - 1 >= 0 && j - 2 >= 0 && dp[i - 1][j] && ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.')))
*/
class Solution {
public:
    bool isMatch(string s, string p) {
		int n1 = s.length(), n2 = p.length();
		// Exceptional Case: 
		if(n1 == 0 && n2 == 0){
			return true;
		}
		if(n1 != 0 && n2 == 0){
			return false;
		}
		// create
		vector<vector<bool>> dp(n1 + 1, vector<bool>(n2 + 1, false));
		// init
		dp[0][0] = true;
		for(int i = 1; i <= n1; i++){
			dp[i][0] = false;
		}
		// dp
		for(int i = 0; i <= n1; i++){
			for(int j = 1; j <= n2; j++){
				if(p[j - 1] != '*'){
					dp[i][j] = (i - 1 >= 0) && dp[i - 1][j - 1] && ((s[i - 1] == p[j - 1]) || (p[j - 1] == '.'));
				}
				else if(p[j - 1] == '*'){
					// attention: ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.')) is different from (s[i - 1] == p[j - 2] || p[j - 2] == '.')
					dp[i][j] = (j - 2 >= 0 && dp[i][j - 2]) || (i - 1 >= 0 && j - 2 >= 0 && dp[i - 1][j] && ((s[i - 1] == p[j - 2]) || (p[j - 2] == '.')));
				}
			}
		}
        return dp[n1][n2];
    }
};

int main(){
	Solution sol;
	string s, p;
	while(cin >> s >> p){
		cout << "ans: " << sol.isMatch(s, p) << endl;
	}
	return 0;
}
