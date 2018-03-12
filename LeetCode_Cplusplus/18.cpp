#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
		vector<vector<int>> ans;
		// Exceptional Case: 
		if(n <= 3){
			return ans;
		}
		// sort
		sort(nums.begin(), nums.end(), cmp);
		int i, j, left, right;
		// two pointers
		for(i = 0; i <= n - 4;){
			for(j = i + 1; j <= n - 3;){
				left = j + 1;
				right = n - 1;
				while(left < right){
					int sum = nums[i] + nums[j] + nums[left] + nums[right];
					if(sum == target){
						vector<int> res = {nums[i], nums[j], nums[left], nums[right]};
						ans.push_back(res);
						left++;
						right--;
						while(left < right && nums[left] == nums[left - 1]){
							left++;
						}
						while(left < right && nums[right] == nums[right + 1]){
							right--;
						}						
					}
					else if(sum < target){
						left++;
						while(left < right && nums[left] == nums[left - 1]){
							left++;
						}
					}
					else if(sum > target){
						right--;
						while(left < right && nums[right] == nums[right + 1]){
							right--;
						}
					}
				}
				j++;
				while(j <= n - 3 && nums[j] == nums[j - 1]){
					j++;
				}
			}
			i++;
			while(i <= n - 4 && nums[i] == nums[i - 1]){
				i++;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<vector<int>> ans = sol.fourSum(nums, target);
	// console output
	for(auto p: ans){
		for(int val: p){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
