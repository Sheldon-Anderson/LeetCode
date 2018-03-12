#include <bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return n;
		}
		// create and init
		vector<pair<int, int>> dp(n, make_pair(1, 1));
		// DP and get answer
		int ans = 0;
		for(int i = 1; i <= n - 1; i++){
			for(int j = 0; j <= i - 1; j++){
				if(nums[i] > nums[j] && dp[j].second + 1 > dp[i].first){
					dp[i].first = dp[j].second + 1;
				}
				if(nums[i] < nums[j] && dp[j].first + 1 > dp[i].second){
					dp[i].second = dp[j].first + 1;
				}
			}
			ans = max(ans, max(dp[i].first, dp[i].second));
		}
		// return answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1,2,3,4,5,6,7,8,9};
	cout << "ans: " << sol.wiggleMaxLength(nums) << endl;
	return 0;
}
