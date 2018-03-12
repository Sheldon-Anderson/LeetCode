#include<bits/stdc++.h>
using namespace std;

#define LL long long

// bucket sort
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int n = nums.size();
		// Exceptional Case: 
		if(n <= 1 || k <= 0 || t <= -1){
			return false;
		}
		// map
		// for case: [-1,2147483647], 1, 2147483647
		map<LL, LL> m;
		// get the minimum value
		int minVal = INT_MAX;
		for(int val: nums){
			minVal = min(minVal, val);
		}
		// bucket sort
		for(int i = 0; i <= n - 1; i++){
			LL delta = (LL)nums[i] - (LL)minVal;
			LL key = delta / ((LL)t + 1); 
			// check
			if(m.count(key) || (m.count(key - 1) && delta - m[key - 1] <= (LL)t) || (m.count(key + 1) && m[key + 1] - delta <= (LL)t)){
				return true;
			}
			// delete
			if(m.size() >= k){
				LL preDelta = (LL)nums[i - k] - (LL)minVal;
				LL preKey = preDelta / ((LL)t + 1);
				m.erase(preKey);
			}
			m[key] = delta;
		}
		return false;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {-1, 2147483647};//  {1, 2, 2, 3, 4};	// {1, 2, 2, 3, 3, 3, 4, 4, 4, 4};
	int k = 1, t = 2147483647;
	cout << "ans: " << sol.containsNearbyAlmostDuplicate(nums, k, t) << endl;
	return 0;
}
