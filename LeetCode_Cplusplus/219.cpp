#include<bits/stdc++.h>
using namespace std;

/*
// Accepted
// map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		if(n == 0){
			return false;
		}
		map<int, int> m1, m2;
		bool flag = false;
		for(int i = 0; i <= n - 1; i++){
			if(m1.count(nums[i])){
				flag = true;
				// save the minimum distance for nums[i]
				if(!m2.count(nums[i])){
					m2[nums[i]] = i - m1[nums[i]];
				}
				else{
					m2[nums[i]] = min(m2[nums[i]], i - m1[nums[i]]);
				}
			}
			m1[nums[i]] = i;
		}
        if(!flag){
			return false;
		}
		for(auto &p: m2){
			if(p.second > k){
				return false;
			}
		}
		return true;
    }
};
*/

// map
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
		int n = nums.size();
		if(n == 0){
			return false;
		}
		// map
		map<int, int> m;
		for(int i = 0; i <= n - 1; i++){
			if(m.count(nums[i]) && (i - m[nums[i]] <= k)){
				return true;
			}
			else{
				m[nums[i]] = i;
			}
		}
		return false;
	}
};

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 2, 3, 3, 3, 4};	// {1, 2, 2, 3, 3, 4, 4, 4};
	int k;
	while(cin >> k){
		cout << "ans: " << sol.containsNearbyDuplicate(nums, k) << endl;
	}
	return 0;
}
