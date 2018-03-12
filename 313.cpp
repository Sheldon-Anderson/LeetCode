#include <bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        if(n <= 1){
			return 1;
		}
		// create and init
		int *dp = new int[n];
		int N = primes.size();
		int *pos = new int[N];
		memset(pos, 0, sizeof(int) * N);
		dp[0] = 1;
		// DP
		for(int i = 1; i <= n - 1; i++){
			int tmp = INT_MAX;
			for(int j = 0; j <= N - 1; j++){
				tmp = min(tmp, dp[pos[j]] * primes[j]);
			}
			dp[i] = tmp;
			for(int j = 0; j <= N - 1; j++){
				while(dp[pos[j]] * primes[j] <= dp[i]){
					pos[j]++;
				}
			}
		}
		// get answer
		return dp[n - 1];
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n = 12;
	vector<int> primes = {2, 7, 13, 19};
	cout << "ans: " << sol.nthSuperUglyNumber(n, primes) << endl;
	return 0;
}
