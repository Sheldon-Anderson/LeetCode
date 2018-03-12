#include<bits/stdc++.h>
using namespace std;

// Dynamic Programming
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
		// Exceptional Case: 
		if(n == 0){
			return 0;
		}
		if(n == 1){
			return nums[0];
		}
		if(n == 2){
			return max(nums[0], nums[1]);
		}
		if(n == 3){
			return max(nums[0], max(nums[1], nums[2]));
		}
		if(n == 4){
			return max(nums[0] + nums[2], nums[1] + nums[3]);
		}
		// create
		int *dp_1 = new int[n - 1];
		int *dp_2 = new int[n - 1];
		// init
		dp_1[0] = nums[0];
		dp_1[1] = nums[1];
		dp_1[2] = nums[0] + nums[2];
		dp_2[0] = nums[1];
		dp_2[1] = nums[2];
		dp_2[2] = nums[1] + nums[3];
		// dp
		for(int i = 3; i <= n - 2; i++){
			dp_1[i] = max(dp_1[i - 2], dp_1[i - 3]) + nums[i];
		}
		for(int i = 3; i <= n - 2; i++){
			dp_2[i] = max(dp_2[i - 2], dp_2[i - 3]) + nums[i + 1];
		}
		// get answer
		int ans = 0;
		for(int i = 0; i <= n - 2; i++){
			ans = max(ans, dp_1[i]);
			ans = max(ans, dp_2[i]);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {2, 1, 4, 3, 6, 5, 8, 7, 10, 9};
	cout << "ans: " << sol.rob(nums) << endl;
	return 0;
}
