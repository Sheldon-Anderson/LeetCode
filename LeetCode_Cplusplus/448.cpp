#include<bits/stdc++.h>

using namespace std;

// bucket sort
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
		for(int i = 0; i <= n - 1;){
			if(nums[i] != i + 1 && nums[nums[i] - 1] != nums[i]){
				swap(nums[i], nums[nums[i] - 1]);
			}
			else{
				i++;
			}
		}
		// get answer
		vector<int> ans;
		for(int i = 0; i <= n - 1; i++){
			if(nums[i] != i + 1){
				ans.push_back(i + 1);
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {4, 3, 2, 7, 8, 2, 3, 1};
	vector<int> ans = sol.findDisappearedNumbers(nums);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
