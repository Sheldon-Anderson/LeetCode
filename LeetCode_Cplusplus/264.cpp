#include <bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n <= 1){
			return 1;
		}
		// create and init
		int *dp = new int[n];
		dp[0] = 1;
		// dp
		int p2 = 0, p3 = 0, p5 = 0;
		for(int i = 1; i <= n - 1; i++){
			dp[i] = min(dp[p2] * 2, min(dp[p3] * 3, dp[p5] * 5));
			while(dp[p2] * 2 <= dp[i]){
				p2++;
			}
			while(dp[p3] * 3 <= dp[i]){
				p3++;
			}
			while(dp[p5] * 5 <= dp[i]){
				p5++;
			}
		}
		// get answer
		return dp[n - 1];
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.nthUglyNumber(n) << endl;
	}
	return 0;
}
