#include<bits/stdc++.h>
using namespace std;

// Boyer-Moore majority vote algorithm
// T(n) = O(n)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
		int n = nums.size();
		if(n == 0){
			return ans;
		}
		if(n == 0){
			ans.push_back(nums[0]);
			return ans;
		}
		int count_1 = 0, count_2 = 0, pos_1 = 0, pos_2 = 1;
		for(int i = 0; i <= n - 1; i++){
			if(nums[pos_1] == nums[i]){
				count_1++;
			}
			else if(nums[pos_2] == nums[i]){
				count_2++;
			}
			else if(count_1 == 0){
				pos_1 = i;
				count_1++;
			}
			else if(count_2 == 0){
				pos_2 = i;
				count_2++;
			}
			else{
				count_1--;
				count_2--;
			}
		}
		// check
		count_1 = count_2 = 0;
		for(int i = 0; i <= n - 1; i++){
			if(nums[pos_1] == nums[i]){
				count_1++;
			}
			else if(nums[pos_2] == nums[i]){
				count_2++;
			}
		}
		if(count_1 > n / 3){
			ans.push_back(nums[pos_1]);
		}
		if(count_2 > n / 3){
			ans.push_back(nums[pos_2]);
		}
		return ans;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	vector<int> nums = {1, 1, 1, 1, 2, 2, 2, 3, 3};
	vector<int> ans = sol.majorityElement(nums);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
