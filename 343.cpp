#include <bits/stdc++.h>
using namespace std;

/*
// dynamic programming
// Accepted
class Solution {
public:
    int integerBreak(int n) {
		if(n <= 0){
			return 0;
		}
		if(n <= 3){
			return n - 1;
		}
		// create and init
		int *dp = new int[n + 1];
		dp[2] = 2;
		dp[3] = 3;
		dp[4] = 4;
		for(int i = 5; i <= n; i++){
			int res = 0;
			for(int j = 2; j <= 2 + (i - 2) / 2 - 1; j++){
				res = max(res, dp[j] * dp[i - j]);
			}
			dp[i] = res;
		}
        return dp[n];
    }
};
*/

// math
class Solution {
public:
    int integerBreak(int n) {
		if(n <= 0){
			return 0;
		}
		if(n <= 3){
			return n - 1;
		}
		// 2->1, 3->2, 4->4, when n <= 4, we don't break it
		int ans = 1;
		while(n > 4){
			ans *= 3;
			n -= 3;
		}
		ans *= n;
		// get answer
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.integerBreak(n) << endl;
	}
	return 0;
}
