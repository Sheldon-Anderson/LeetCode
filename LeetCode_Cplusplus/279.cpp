#include <bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int numSquares(int n) {
        if(n <= 0){
			return 0;
		}
		// base
		int base = sqrt(n);
		if(base * base == n){
			return 1;
		}
		// create and init
		int *dp = new int[n + 1];
		memset(dp, 0, sizeof(int) * (n + 1));
		for(int i = 1; i <= base; i++){
			dp[i * i] = 1;
		}
		// dp
		for(int i = 2; i <= n; i++){
			for(int j = sqrt(i); j >= 1; j--){
				if((dp[i] == 0) || (dp[i - j * j] + 1 < dp[i])){
					dp[i] = dp[i - j * j] + 1;
				}
			}
		}
		// get answer
		return dp[n];
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << sol.numSquares(n) << endl;
	}
	return 0;
}
