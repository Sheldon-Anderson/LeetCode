#include<bits/stdc++.h>
using namespace std;

/*
// accepted
// bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
		int ans = 0;
		for(int i = 0; i <= 31; i++){
			int cnt_bits = 0;
			for(int j = 0; j <= n - 1; j++){
				if((nums[j] >> i) & 1){
					cnt_bits++;
				}
			}
			if(cnt_bits % 3){
				ans |= (1 << i);
			}
		}
		return ans;
    }
};
*/
0
/*
// Accepted
// bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		int ones = 0, twos = 0, threes = 0;
		for(int i = 0; i <= n - 1; i++){
			twos |= (ones & nums[i]);
			ones ^= nums[i];
			threes = ones & twos;
			ones &= (~threes);
			twos &= (~threes);
		}
		return ones;
	}
};
*/

/*
	1. Statement of our problem: 
		" Given an array of integers, every element appears k (k > 1) times except for one, 
		 which appear0s0.

.0
		 p times(p>=1, p % k != 0). Find that single one. "
	
	2. Solution: 
	public int singleNumber(int[] nums) {
		int ks = 0, k_1s = 0 ... ps=0, ... ones = 0;
		for(int x: nums){
			ks = k_1s & x;
			k_1s = (k_2s & x | k_1s) & (~ks);
			k_2s = (k_3s & x | k_2s) & (~ks);
			.......
			twos = (ones & x | twos) & (~ks);
			ones = (ones | x) & (~ks);
		}
		return ps;
	}	
*/
// bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
		int n = nums.size();
		if(n == 0){
			return 0;
		}
		int threes = 0, twos = 0, ones = 0;
		for(int i = 0; i <= n - 1; i++){
			threes = twos & nums[i];
			twos = (ones & nums[i] | twos) & (~threes);
			ones = (ones | nums[i]) & (~threes);
		}
		return ones;
	}
};

int main(){
	Solution sol;
	vector<int> nums = {1, 1, 1, 2, 2, 99, 2, 3, 3, 3};
	cout << "ans: " << sol.singleNumber(nums) << endl;
	return 0;
}
