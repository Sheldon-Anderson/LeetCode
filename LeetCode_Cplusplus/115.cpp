#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n1 = s.length(), n2 = t.length();
		if(!n1 && !n2){
			return 1;
		}
		if(n1 && !n2){
			return 1;
		}
		if(!n1 && n2){
			return 0;
		}
		// create
		int **dp = new int*[n1 + 1];
		for(int i = 0; i <= n1; i++){
			dp[i] = new int[n2 + 1];
		}
		// init
		dp[0][0] = 1;
		for(int i = 1; i <= n1; i++){
			dp[i][0] = 1;
		}
		for(int i = 1; i <= n2; i++){
			dp[0][i] = 0;
		}
		// dp
		for(int i = 1; i <= n1; i++){
			for(int j = 1; j <= n2; j++){
				dp[i][j] = dp[i - 1][j] + ((s[i - 1] == t[j - 1])? dp[i - 1][j - 1]: 0);
			}
		}
		return dp[n1][n2];
    }
};

int main(){
	Solution sol;
	string s, t;
	while(cin >> s >> t){
		cout << "ans: " << sol.numDistinct(s, t) << endl;
	}
	return 0;
}
