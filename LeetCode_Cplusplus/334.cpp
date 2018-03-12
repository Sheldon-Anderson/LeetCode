#include <bits/stdc++.h>
using namespace std;

/*
// LIS algorithm (including binary_search)
// T(n) = O(nlogn), S(n) = O(n)
class Solution {
private: 
	int binary_search(vector<int> &B, int target){
		int left = 0, right = B.size() - 1;
		while(left <= right){
			int mid = (left + right) >> 1;
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
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
		if(n <= 2){
			return false;
		}
		vector<int> B;
		B.push_back(nums[0]);
		int ans = 1;
		// LIS
		for(int i = 1; i <= n - 1; i++){
			if(nums[i] > B[ans - 1]){
				B.push_back(nums[i]);
				ans++;
			}
			else if(nums[i] <= B[ans - 1]){
				// find the first pos that B[pos] >= nums[i]
				int pos = binary_search(B, nums[i]);
				B[pos] = nums[i];
			}
		}
		// get answer
		return ans >= 3;
    }
};
*/

// easy method
// T(n) = O(n), s(n) = O(1)
class Solution{
public:
    bool increasingTriplet(vector<int>& nums) {
		int n = nums.size();
		if(n <= 2){
			return false;
		}
		// small, medium, large
		int small = INT_MAX, medium = INT_MAX;
		for(int i = 0; i <= n - 1; i++){
			if(nums[i] <= small){
				small = nums[i];
			}
			else if(nums[i] <= medium){
				medium = nums[i];
			}
			// find the large
			else{
				return true;
			}
		}
		// get answer
		return false;
	}
};

int main(int argc, char** argv){
	Solution sol;
	// {5, 4, 3, 2, 1};		{1, 2, 3, 4, 5};
	vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
	cout << "ans: " << sol.increasingTriplet(nums) << endl;
	return 0;
}
