#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		// Exceptional Case: 
		if(nums.empty()){
			return vector<int>();
		}
        int n = nums.size();
		vector<int> ans(n, 1);
		// from left to right
		int left = 1;
		for(int i = 0; i <= n - 1; i++){
			ans[i] *= left;
			left *= nums[i];
		}
		// from right to left
		int right = 1;
		for(int i = n - 1; i >= 0; i--){
			ans[i] *= right;
			right *= nums[i];
		}
		return ans;
    }
};

int main(int agrc, char** argv){
	Solution sol;
	vector<int> nums = {1, 2, 3, 4};
	vector<int> ans =  sol.productExceptSelf(nums);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
