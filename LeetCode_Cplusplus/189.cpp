#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
		if(n <= 1){
			return;
		}
		k = k % n;
		while(k--){
			nums.insert(nums.begin(), nums[n - 1]);
			nums.pop_back();
		}
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
	int k = 3;
	// output 1
	for(int val: nums){
		cout << val << " ";
	}
	cout << endl;
	sol.rotate(nums, k);
	// output 2
	for(int val: nums){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
