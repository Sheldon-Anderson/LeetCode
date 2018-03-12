#include<bits/stdc++.h>

using namespace std;

/*
// knapsack problem: dynamic programming
// T(n * sum) = O(n * sum), S(n * sum) = O(n * sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		// check
		if(sum & 1){
			return false;
		}
		sum /= 2;
		// create and init
		bool **dp = new bool*[n + 1];
		for(int i = 0; i <= n; i++){
			dp[i] = new bool[sum + 1];
		}
		dp[0][0] = true;
		for(int i = 1; i <= n; i++){
			dp[i][0] = true;
		}
		for(int i = 1; i <= sum; i++){
			dp[0][i] = false;
		}
		// DP
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= sum; j++){
				if(j < nums[i - 1]){
					dp[i][j] = dp[i - 1][j];
				}
				else{
					dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
				}
			}
		}
		// get answer
		return dp[n][sum];
    }
};
*/

// knapsack problem: dynamic programming
// T(n * sum) = O(n * sum), S(sum) = O(sum)
class Solution {
public:
    bool canPartition(vector<int>& nums) {
		int n = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		// check
		if(sum & 1){
			return false;
		}
		sum >>= 1;
		// create and init
		bool *dp = new bool[sum + 1];
		memset(dp, false, sizeof(bool) * (sum + 1));
		dp[0] = true;
		// DP
		for(int i = 0; i <= n - 1; i++){
			for(int j = sum; j >= nums[i]; j--){
				dp[j] = dp[j] || dp[j - nums[i]];
			}
		}
		// get answer
		return dp[sum];
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 5, 11, 5};	// {1, 2, 3, 5};
	cout << "ans: " << sol.canPartition(nums) << endl;
	return 0;
}
