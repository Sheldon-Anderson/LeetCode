#include<bits/stdc++.h>
using namespace std;

// DFS + binary search
class Solution {
private: 
	int ans;
	
	void DFS(vector<int>& nums, int left, int right){
		// debug
		// cout << "left: " << left << ", right: " << right << endl;
		if(left > right){
			return;
		}
		if(left == right){
			ans = min(ans, nums[left]);
			return;
		}
		int mid = (left + right) >> 1;
		if(nums[left] == nums[mid] && nums[mid] == nums[right]){
			ans = min(ans, nums[left]);
			DFS(nums, left, mid - 1);
			DFS(nums, mid + 1, right);
		}
		else if(nums[left] <= nums[mid]){
			ans = min(ans, nums[left]);
			DFS(nums, mid + 1, right);
		}
		else if(nums[mid] <= nums[right]){
			ans = min(ans, nums[mid]);
			DFS(nums, left, mid - 1);
		}
	}

public:
    int findMin(vector<int>& nums) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		ans = INT_MAX;
		DFS(nums, 0, n - 1);
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {4, 5, 6, 7, 0, 1, 2};	// {3, 3, 3, 1, 3};
	cout << "ans: " << sol.findMin(nums) << endl;
	return 0;
}
