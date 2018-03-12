#include <bits/stdc++.h>
using namespace std;

// dynamic programming + binary_search
class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

	int binary_search(vector<int>& coins, int left, int right, int target){
		while(left <= right){
			int mid = (left + right) >> 1;
			if(coins[mid] < target){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return right;
	}
	
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0){
			return 0;
		}
		int n = coins.size();
		if(n == 0){
			return -1;
		}
		// create and init
		int *dp = new int[amount + 1];
		memset(dp, 0, sizeof(int) * (amount + 1));
		for(int i = 0; i <= n - 1; i++){
			if(coins[i] <= amount){
				dp[coins[i]] = 1;
			}
		}
		// sort
		sort(coins.begin(), coins.end(), cmp);
		// DP
		for(int i = coins[0]; i <= amount; i++){
			if(dp[i] == 1){
				continue;
			}
			int pos = binary_search(coins, 0, n - 1, i);
			for(int j = 0; j <= pos; j++){
				if(dp[coins[j]] && dp[i - coins[j]] && (dp[i] == 0 || (dp[coins[j]] + dp[i - coins[j]] < dp[i]))){
					dp[i] = dp[coins[j]] + dp[i - coins[j]];
				}
			}
		}
		// get answer
		return dp[amount] == 0? -1: dp[amount];
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> coins = {1, 2, 5};
	int amount;
	for(amount = 1; amount <= 11; amount++){
		cout << "amount: " << amount << ", ans: " << sol.coinChange(coins, amount) << endl;		
	}
	return 0;
}
