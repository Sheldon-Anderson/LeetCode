#include<bits/stdc++.h>

using namespace std;

// bit manipulation
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        if(!nums.size()){
			return 0;
		}
		int ans = 0;
		for(int i = 31; i >= 0; i--){
			int cnt_zeros = 0, cnt_ones = 0;
			for(int val: nums){
				if((1 << i) & val){
					cnt_ones++;
				}
				else{
					cnt_zeros++;
				}
			}
			ans += cnt_ones * cnt_zeros;
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {4, 14, 2};
	cout << "ans: " << sol.totalHammingDistance(nums) << endl;
	return 0;
}
