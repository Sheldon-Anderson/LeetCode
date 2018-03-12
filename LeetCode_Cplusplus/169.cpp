#include<bits/stdc++.h>
using namespace std;

// count
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return -1;
		}
		if(n == 1){
			return nums[0];
		}
		int count = 0, pos = -1;
		for(int i = 0; i <= n - 1; i++){
			if(!count){
				count++;
				pos = i;
			}
			else{
				if(nums[i] == nums[pos]){
					count++;
				}
				else{
					count--;
				}
			}
		}
		// check
		if(pos != -1){
			count = 0;
			for(int i = 0; i <= n - 1; i++){
				if(nums[i] == nums[pos]){
					count++;
				}
			}
			if(count > n / 2){
				return nums[pos];
			}
		}
		return -1;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 3, 3, 3, 3, 4, 4};
	cout << "ans: " << sol.majorityElement(nums) << endl;
	return 0;
}
