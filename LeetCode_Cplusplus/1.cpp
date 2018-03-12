#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
		map<int, int> m;
		vector<int> ans(2, 0);
		for(int i = 0; i <= n - 1; i++){
			if(!m.count(nums[i]) && !m.count(target - nums[i])){
				m[nums[i]] = i;
			}
			else if(m.count(nums[i]) && !m.count(target - nums[i])){
				continue;
			}
			else if(m.count(target - nums[i])){
				// debug
				// cout << target - nums[i] << ", " << nums[i] << endl;
				ans[0] = m[target - nums[i]];
				ans[1] = i;
				break;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {2, 7, 11, 15};
	int target = 9;
	vector<int> ans = sol.twoSum(nums, target);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
