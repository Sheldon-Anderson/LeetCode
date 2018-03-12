#include <bits/stdc++.h>
using namespace std;

// dynamic programming
// similar to 322. Coin Change
class Solution{
private: 
	// sort compare function
	static int cmp(const int &a, const int &b){
		return a < b;
	}

	// find the last pos that nums[pos] < target
	int binary_search(vector<int>& nums, int left, int right, int target){
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(nums[mid] < target){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return right;
	}
	
public:
    int combinationSum4(vector<int>& nums, int target) {
		if(target <= 0){
			return 0;
		}
		int n = nums.size();
		if(!n){
			return 0;
		}
		// sort
		sort(nums.begin(), nums.end(), cmp);
		// create and init
		int *dp = new int[target + 1];
		memset(dp, 0, sizeof(int) * (target + 1));
		for(int i = 0; i <= n - 1; i++){
			if(nums[i] <= target){
				dp[nums[i]] = 1;
			}
			else{
				break;
			}
		}
		// DP
		for(int i = nums[0]; i <= target; i++){
			int pos = binary_search(nums, 0, n - 1, i);
			for(int j = 0; j <= pos; j++){
				if(dp[i - nums[j]]){
					dp[i] += dp[i - nums[j]];
				}
			}
		}
		// get answer
		return dp[target];
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 2, 3};
	int target = 32;
	cout << "ans: " << sol.combinationSum4(nums, target);
	return 0;
}
