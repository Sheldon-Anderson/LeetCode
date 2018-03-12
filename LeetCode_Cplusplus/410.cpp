#include<bits/stdc++.h>

using namespace std;

// binary_search
class Solution {
private: 

	// check if mid is a possible valid answer
	bool check(vector<int> &nums, int n, int m, int mid){
		// init: cnt = 1 rather than cnt = 0!
		int sum = 0, cnt = 1;
		for(int i = 0; i <= n - 1; i++){
			sum += nums[i];
			if(sum > mid){
				if(++cnt > m){
					return false;
				}
				sum = nums[i];
			}
		}
		return true;
	}

public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
		int sum = accumulate(nums.begin(), nums.end(), 0);
		vector<int>::iterator maxVal = max_element(nums.begin(), nums.end());
		// Exceptional Case: 
		if(m == 1){
			return sum;
		}
		if(m == n){
			return *maxVal;
		}
		// binary_search
		int left = *maxVal, right = sum;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(check(nums, n, m, mid)){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		return left;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {7, 2, 5, 10, 8};
	int m = 2;
	cout << "ans: " << sol.splitArray(nums, m) << endl;
	return 0;
}
