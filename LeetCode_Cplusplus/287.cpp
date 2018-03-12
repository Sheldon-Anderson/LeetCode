#include <bits/stdc++.h>
using namespace std;

/*
// signed flag
// Accepted
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return -1;
		}
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			ans = nums[i] < 0? -nums[i]: nums[i];
			if(nums[ans] > 0){
				nums[ans] = -nums[ans];
			}
			else{
				break;
			}
		}
		// recover the numbers
		for(int i = 0; i <= n - 1; i++){
			if(nums[i] < 0){
				nums[i] = -nums[i];
			}
		}
		// get answer
		return ans;
    }
};
*/

/*
// 142. Linked List Cycle II
// Accepted
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1){
			return -1;
		}
		int p = nums[0], q = nums[nums[0]];
		while(p != q){
			p = nums[p];
			q = nums[nums[q]];
		}
		// find the duplicate
		p = 0;
		while(p != q){
			p = nums[p];
			q = nums[q];
		}
		// get answer
		return p;
	}
};
*/

// binary search
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1){
			return -1;
		}
		int left = 1, right = n - 1;
		while(left < right){
			int mid = left + ((right - left) >> 1);
			int cnt = 0;
			// check the numbers that <= mid
			for(int i = 0; i <= n - 1; i++){
				if(nums[i] <= mid){
					cnt++;
				}
			}
			if(cnt <= mid){
				left = mid + 1;
			}
			else{
				right = mid;
			}
		}
		return right;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {2, 3, 1, 4, 5, 1};
	cout << "ans: " << sol.findDuplicate(nums) << endl;
	return 0;
}
