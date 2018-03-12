#include <bits/stdc++.h>
using namespace std;

// LIS Algorithm: Longest Increasing Subsequence
// use binary search
// T(n) = O(nlogn)
class Solution {
private: 
	int binary_search(vector<int> &B, int target){
		int left = 0, right = B.size() - 1;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(target > B[mid]){
				left = mid + 1;
			}
			else if(target <= B[mid]){
				right = mid - 1;
			}
		}
		return left;
	}

public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return n;
		}
		vector<int> B;
		B.push_back(nums[0]);
		int Len = 1;
		// LIS
		for(int i = 1; i <= n - 1; i++){
			if(nums[i] > B[Len - 1]){
				B.push_back(nums[i]);
				Len++;
			}
			else if(nums[i] <= B[Len - 1]){
				// find the first pos that B[pos] >= nums[i]
				int pos = binary_search(B, nums[i]);
				B[pos] = nums[i];
			}
		}
		// get answer
		return Len;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << "ans: " << sol.lengthOfLIS(nums) << endl;
	return 0;
}
