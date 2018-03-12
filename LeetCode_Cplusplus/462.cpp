#include<bits/stdc++.h>

using namespace std;

// math: find the median number
class Solution {
private: 
	// quicksort partition function
	int partition(vector<int> &nums, int left, int right){
		int i = left, j = right + 1;
		int pivot = nums[left];
		while(true){
			while(nums[++i] < pivot && i < right);
			while(nums[--j] > pivot && i > left);
			if(i >= j){
				break;
			}
			swap(nums[i], nums[j]);
		}
		swap(nums[left], nums[j]);
		return j;
	}

	// binary search
	int findK(vector<int> &nums, int left, int right, int k){
		while(left < right){
			int pos = partition(nums, left, right);
			if(pos + 1 == k){
				break;
			}
			else if(pos + 1 > k){
				right = pos - 1;
			}
			else if(pos + 1 < k){
				left = pos + 1;
			}
		}
		return nums[k - 1];
	}
	
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return 0;
		}
		int median = findK(nums, 0, n - 1, (n + 1) / 2);
		// get answer
		int ans = 0;
		for(int val: nums){
			ans += abs(val - median);
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {5, 1, 2, 6, 3, 4};
	cout << "ans: " << sol.minMoves2(nums) << endl;
	return 0;
}
