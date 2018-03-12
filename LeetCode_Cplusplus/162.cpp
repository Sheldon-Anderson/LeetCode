#include<bits/stdc++.h>
using namespace std;

// DFS + binary search
class Solution {
private: 
	int ans;

	void DFS(vector<int>& nums, int left, int right){
		if(ans != -1){
			return;
		}
		if(left == right){
			if((nums[left - 1] < nums[left]) && (nums[left] > nums[left + 1])){
				ans = left;
				return;
			}
		}
		int mid = (left + right) >> 1;
		if((nums[mid - 1] < nums[mid]) && (nums[mid] > nums[mid + 1])){
			ans = mid;
			return;
		}
		if(left <= mid - 1){
			DFS(nums, left, mid - 1);
		}
		if(mid + 1 <= right){
			DFS(nums, mid + 1, right);
		}
	}

public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
		// Exceptional Case: 
		if(n <= 1){
			return n - 1;
		}
		// check start and end
		if(nums[0] > nums[1]){
			return 0;
		}
		if(nums[n - 2] < nums[n - 1]){
			return n - 1;
		}
		ans = -1;
		DFS(nums, 1, n - 2);
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 3, 4};
	cout << "ans: " << sol.findPeakElement(nums) << endl;
	return 0;
}
