#include<bits/stdc++.h>
using namespace std;

// bit manipulation
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
		for(int val: nums){
			ans ^= val;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 1, 2, 2, 99, 3, 3, 4, 4};
	cout << "ans: " << sol.singleNumber(nums) << endl;
	return 0;
}
