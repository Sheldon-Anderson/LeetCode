#include<bits/stdc++.h>
using namespace std;

// bit manipulation
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
		vector<int> ans;
        int n = nums.size();
		if(n == 2){
			ans.push_back(nums[0]);
			ans.push_back(nums[1]);
			return ans;
		}
		int res = 0;
		for(int i = 0; i <= n - 1; i++){
			res ^= nums[i];
		}
		// find the different bit
		int pos = -1;
		for(int i = 31; i >= 0; i--){
			if((1 << i) & res){
				pos = i;
				break;
			}
		}
		// split two elements
		int e1 = 0, e2 = 0;
		for(int i = 0; i <= n - 1; i++){
			if((1 << pos) & nums[i]){
				e1 ^= nums[i];
			}
			else{
				e2 ^= nums[i];
			}
		}
		ans.push_back(e1);
		ans.push_back(e2);
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 2, 1, 3, 2, 5};
	vector<int> ans = sol.singleNumber(nums);
	// console output
	cout << ans[0] << ", " << ans[1] << endl;
	return 0;
}
