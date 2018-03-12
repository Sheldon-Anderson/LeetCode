#include<bits/stdc++.h>
using namespace std;

// bit manipulation
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return -1;
		}
		int ans = 0;
		for(int i = 0; i <= n; i++){
			ans ^= i;
		}
		for(int i = 0; i <= n - 1; i++){
			ans ^= nums[i];
		}
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {0, 1, 3};
	cout << "ans: " << sol.missingNumber(nums) << endl;
	return 0;
}
