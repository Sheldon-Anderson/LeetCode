#include<bits/stdc++.h>
using namespace std;

/*
// at most two transactions
// scan from left to right and right to left
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if(n <= 1){
			return 0;
		}
		// from left to right
		vector<int> profits_left(n, 0);
		int profit_left = 0;
		int min_left = prices[0];
		for(int i = 1; i <= n - 1; i++){
			if(prices[i] < min_left){
				min_left = prices[i];
			}
			else if(prices[i] > min_left){
				profit_left = max(profit_left, prices[i] - min_left);
			}
			profits_left[i] = profit_left;
		}
		// from right to left
		vector<int> profits_right(n, 0);
		int profit_right = 0;
		int max_right = prices[n - 1];
		for(int i = n - 2; i >= 0; i--){
			if(prices[i] > max_right){
				max_right = prices[i];
			}
			else if(prices[i] < max_right){
				profit_right = max(profit_right, max_right - prices[i]);
			}
			profits_right[i] = profit_right;
		}
		// get answer
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			ans = max(ans, profits_left[i] + profits_right[i]);
		}
		return ans;
    }
};
*/

// at most two transactions
// dynamic programming
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if(n <= 1){
			return 0;
		}
		// create
		// k = 2, dp[k + 1][n]
		int **dp = new int*[3];
		for(int i = 0; i <= 2; i++){
			dp[i] = new int[n];
		}
		// init
		for(int i = 0; i <= 2; i++){
			dp[i][0] = 0;
		}
		for(int i = 0; i <= n - 1; i++){
			dp[0][i] = 0;
		}
		// dp
		for(int i = 1; i <= 2; i++){
			int local_max = -prices[0];
			for(int j = 1; j <= n - 1; j++){
				dp[i][j] = max(dp[i][j - 1], local_max + prices[j]);
				local_max = max(local_max, dp[i - 1][j - 1] - prices[j]);
			}
		}
		// get answer
		return dp[2][n - 1];
	}
};

int main(){
	Solution sol;
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	cout << "ans: " << sol.maxProfit(prices) << endl;
	return 0;
}
