#include<bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return 0;
		}
		// create and init
		int *dp_min = new int[n];
		int *dp_max = new int[n];
		dp_max[0] = dp_min[0] = nums[0];
		// dp
		for(int i = 1; i <= n - 1; i++){
			if(nums[i] == 0){
				dp_min[i] = dp_max[i] = 0;
			}
			else if(nums[i] > 0){
				dp_min[i] = min(dp_min[i - 1] * nums[i], nums[i]);
				dp_max[i] = max(dp_max[i - 1] * nums[i], nums[i]);
			}
			else{
				dp_min[i] = min(dp_max[i - 1] * nums[i], nums[i]);
				dp_max[i] = max(dp_min[i - 1] * nums[i], nums[i]);				
			}
		}
		// get answer	
		int ans = INT_MIN;
		for(int i = 0; i <= n - 1; i++){
			ans = max(ans, dp_max[i]);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {2, 3, -2, 4};
	cout << "ans: " << sol.maxProduct(nums) << endl;
	return 0;
}
