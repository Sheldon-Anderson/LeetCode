#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
		// Exceptional Case: 
		if(n <= 2){
			return 0;
		}
		// sort
		sort(nums.begin(), nums.end(), cmp);
		int ans, delta = INT_MAX;
		int left, right;
		for(int i = 0; i <= n - 3;){
			left = i + 1;
			right = n - 1;
			bool flag = false;
			while(left < right){
				int sum = nums[i] + nums[left] + nums[right];
				// debug
				// cout << "sum: " << sum << ", i: " << i << ", left: " << left << ", right: " << right << endl;
				if(sum == target){
					ans = sum;
					flag = true;
					break;
				}
				else if(sum < target){
					// check
					if(target - sum < delta){
						delta = target - sum;
						ans = sum;
					}
					left++;
					while(left < right && nums[left] == nums[left - 1]){
						left++;
					}
				}
				else if(sum > target){
					// check
					if(sum - target < delta){
						delta = sum - target;
						ans = sum;
					}
					right--;
					while(left < right && nums[right] == nums[right + 1]){
						right--;
					}
				}
			}
			if(flag){
				break;
			}
			i++;
			while(i <= n - 3 && nums[i] == nums[i - 1]){
				i++;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {-1, 2, 1, -4};
	int target = 1;
	cout << "ans: " << sol.threeSumClosest(nums, target) << endl;
	return 0;
}
