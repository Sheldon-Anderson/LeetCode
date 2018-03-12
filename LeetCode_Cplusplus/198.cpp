#include<bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return 0;
		}
		if(n == 1){
			return nums[0];
		}
		if(n == 2){
			return max(nums[0], nums[1]);
		}
		// create and init (n >= 3)
		int *dp = new int[n];
		dp[0] = nums[0];
		dp[1] = nums[1];
		dp[2] = nums[0] + nums[2];
		for(int i = 3; i <= n - 1; i++){
			dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
		}
		// get answer
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			ans = max(ans, dp[i]);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 3, 2, 4, 5, 6};
	cout << "ans: " << sol.rob(nums) << endl;
	return 0;
}
