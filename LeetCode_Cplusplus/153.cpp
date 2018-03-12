#include<bits/stdc++.h>
using namespace std;

// binary search
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return -1;
		}
		int left = 0, right = n - 1;
		int ans = INT_MAX;
		while(left <= right){
			if(left == right){
				ans = min(ans, nums[left]);
				break;
			}
			int mid = (left + right) >> 1;
			if(nums[left] <= nums[mid]){
				ans = min(ans, nums[left]);
				left = mid + 1;
			}
			else if(nums[mid] <= nums[right]){
				ans = min(ans, nums[mid]);
				right = mid - 1;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};	// {4, 5, 6, 7, 0, 1, 2};
    cout << "ans: " << sol.findMin(nums) << endl;
	return 0;
}
