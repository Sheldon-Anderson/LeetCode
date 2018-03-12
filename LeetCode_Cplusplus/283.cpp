#include <bits/stdc++.h>
using namespace std;

// two pointers
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return;
		}
		int left = 0, right = 0;
		while(left <= right && right <= n - 1){
			while(left <= n - 1 && nums[left] != 0){
				left++;
			}
			right = left;
			while(right <= n - 1 && nums[right] == 0){
				right++;
			}
			if(left <= right && right <= n - 1){
				swap(nums[left], nums[right]);
			}
		}
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 0, 3, 0, 0, 12, 0, 0, 0};
	sol.moveZeroes(nums);
	// output
	for(int val: nums){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
