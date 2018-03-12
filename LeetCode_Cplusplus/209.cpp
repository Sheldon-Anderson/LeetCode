#include<bits/stdc++.h>
using namespace std;

/*
// T(n) = O(n)
// Two Pointers
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return 0;
		}
		int ans = INT_MAX;
		int left = 0, right = 0, sum = nums[0];
		while(left <= right && right <= n - 1){
			if(sum >= s){
				ans = min(ans, right - left + 1);
				sum -= nums[left++];
				if(left > right){
					right = left;
				}
			}
			else{
				right++;
				if(right <= n - 1){
				    sum += nums[right];
				}
			}
		}
		return ans == INT_MAX? 0: ans;
    }
};
*/

// Binary Search
// T(n) = nlog(n)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		// create and init
		int *sum = new int[n];
		sum[0] = nums[0];
		for(int i = 1; i <= n - 1; i++){
			sum[i] = nums[i] + sum[i - 1];
		}
		// check
		if(sum[n - 1] < s){
			return 0;
		}
		// binary search
		int ans = INT_MAX;
		for(int i = 0; i <= n - 1; i++){
			if(sum[i] >= s){
				int left = 0, right = i, pos = -1;
				while(left <= right){
					int mid = (left + right) >> 1;
					if(sum[mid] > sum[i] - s){
						right = mid - 1;
					}
					else if(sum[mid] <= sum[i] - s){
						pos = mid;
						left = mid + 1;
					}
				}
				ans = min(ans, i - pos);
			}
		}
		return ans;
	}
};

int main(){
	Solution sol;
	int s = 7;
	vector<int> nums = {7, 3, 1, 2, 4, 3};
	cout << "ans: " << sol.minSubArrayLen(s, nums) << endl;
	return 0;
}
