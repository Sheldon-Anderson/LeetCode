#include<bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int minCut(string s) {
        int n = s.length();
		if(n == 0){
			return 0;
		}
		// create and init
		bool **dp = new bool*[n];
		for(int i = 0; i <= n - 1; i++){
			dp[i] = new bool[n];
			memset(dp[i], false, sizeof(bool) * n);
		}
		int *cuts = new int[n];
		memset(cuts, 0, sizeof(int) * n);
		// dp
		// i: end, j: start
		for(int i = 0; i <= n - 1; i++){					
			int min_cuts = i;
			for(int j = 0; j <= i; j++){
				if((s[j] == s[i]) && ((j == i) || (j + 1 == i) || (j + 1 <= i - 1 && dp[j + 1][i - 1]))){
					if(j == 0){
						min_cuts = 0;
					}
					else{
						min_cuts = min(min_cuts, cuts[j - 1] + 1);
					}
					dp[j][i] = true;
				}
				else{
					dp[j][i] = false;
				}
			}
			cuts[i] = min_cuts;
		}
		// get answer
		return cuts[n - 1];
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.minCut(s) << endl;
	}
	return 0;
}
