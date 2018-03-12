#include<bits/stdc++.h>
using namespace std;

// at most k transactions
// dynamic programming + greedy
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
		if(k <= 0 || n <= 1){
			return 0;
		}
		int ans = 0;
		// k >= n / 2, greedy
		if(k >= n / 2){
			for(int i = 1; i <= n - 1; i++){
				if(prices[i] > prices[i - 1]){
					ans += prices[i] - prices[i - 1];
				}
			}
			return ans;
		}
		// create
		int **dp = new int*[k + 1];
		for(int i = 0; i <= k; i++){
			dp[i] = new int[n];
		}
		// init
		for(int i = 0; i <= k; i++){
			dp[i][0] = 0;
		}
		for(int i = 0; i <= n - 1; i++){
			dp[0][i] = 0;
		}
		// dp
		for(int i = 1; i <= k; i++){
			int local_max = -prices[0];
			for(int j = 1; j <= n - 1; j++){
				dp[i][j] = max(dp[i][j - 1], local_max + prices[j]);
				local_max = max(local_max, dp[i - 1][j - 1] - prices[j]);
			}
		}
		// get answer
		ans = dp[k][n - 1];
		return ans;
    }
};

int main(){
	Solution sol;
	int k = 2;
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	cout << "ans: " << sol.maxProfit(k, prices) << endl;
	return 0;
}
