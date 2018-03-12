#include <bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return 0;
		}
		if(n == 1){
			return nums[0];
		}
		if(n == 2){
			return nums[0] * nums[1] + max(nums[0], nums[1]);
		}
		// filter and add two 1s at the beginning and the end
		vector<int> A;
		for(int i = 0; i <= n - 1; i++){
			if(nums[i]){
				A.push_back(nums[i]);
			}
		}
		A.insert(A.begin(), 1);
		A.push_back(1);
		int N = A.size();
		if(N <= 2){
			return 0;
		}
		// create and init
		vector<vector<int>> dp(N, vector<int>(N, 0));
		// DP
		for(int step = 2; step <= N - 1; step++){
			for(int left = 0; left <= N - 1 - step; left++){
				int right = left + step;
				for(int i = left + 1; i <= right - 1; i++){
					dp[left][right] = max(dp[left][right], A[left] * A[i] * A[right] + dp[left][i] + dp[i][right]);
				}
			}
		}
		// get answer
		return dp[0][N - 1];
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int>  nums = {3, 0, 1, 0, 5, 0, 0, 8};
	cout << "ans: " << sol.maxCoins(nums) << endl;
	return 0;
}
