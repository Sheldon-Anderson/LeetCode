#include<bits/stdc++.h>
using namespace std;

// two points
class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
		vector<vector<int>> ans;
		// Exceptional Case: 
		if(n <= 2){
			return ans;
		}
		// sort
		sort(nums.begin(), nums.end(), cmp);
		int left, right;
		for(int i = 0; i <= n - 3;){
			left = i + 1;
			right = n - 1;
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				if(sum == 0){
					vector<int> res = {nums[i], nums[left], nums[right]};
					ans.push_back(res);
					left++;
					right--;
					// skip the same values
					while(left < right && nums[left] == nums[left - 1]){
						left++;
					}
					while(left < right && nums[right] == nums[right + 1]){
						right--;
					}
				}
				else if(sum < 0){
					left++;
					while(left < right && nums[left] == nums[left - 1]){
						left++;
					}
				}
				else if(sum > 0){
					right--;
					while(left < right && nums[right] == nums[right + 1]){
						right--;
					}
				}
			}
			i++;
			while(i <= n - 1 && nums[i] == nums[i - 1]){
				i++;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> ans = sol.threeSum(nums);
	// console output
	for(auto p: ans){
		for(int val: p){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
