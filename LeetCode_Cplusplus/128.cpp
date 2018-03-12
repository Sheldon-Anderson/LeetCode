#include<bits/stdc++.h>
using namespace std;

// set
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return 0;
		}
		set<int> s(nums.begin(), nums.end());
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			if(!s.size()){
				break;
			}
			if(!s.count(nums[i])){
				continue;
			}
			int cnt = 0, left = nums[i] - 1, right = nums[i];
			// x, x + 1, ..., left
			while(s.count(left)){
				s.erase(left);
				cnt++;
				left--;
			}
			// right, right + 1, ..., y
			while(s.count(right)){
				s.erase(right);
				cnt++;
				right++;
			}
			ans = max(ans, cnt);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {100, -4, 200, -1, -3, -2};
	cout << "ans: " << sol.longestConsecutive(nums) << endl;
	return 0;
}
