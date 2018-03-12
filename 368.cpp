#include <bits/stdc++.h>
using namespace std;

// dynamic programming + map
class Solution {
private: 
	static int cmp(const int &a, const int &b){
		return a < b;
	}

public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
		if(n == 0){
			return vector<int>();
		}
		if(n == 1){
			return vector<int>{nums[0]};
		}
		// sort
		sort(nums.begin(), nums.end(), cmp);
		// create and init
		int *dp = new int[n];
		for(int i = 0; i <= n - 1; i++){
			dp[i] = 1;
		}
		// DP
		map<int, int> pre;
		pre[0] = -1;
		for(int i = 1; i <= n - 1; i++){
			for(int j = 0; j <= i - 1; j++){
				if(nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]){
					dp[i] = dp[j] + 1;
					pre[i] = j;
				}
			}
			if(!pre.count(i)){
				pre[i] = -1;
			}
		}
		// get path answer
		vector<int> ans;
		int res = 0, pos = -1;
		for(int i = 0; i <= n - 1; i++){
			if(dp[i] > res){
				res = dp[i];
				pos = i;
			}
		}
		while(pre.count(pos)){
			ans.insert(ans.begin(), nums[pos]);
			pos = pre[pos];
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {4, 8, 10, 240};
	vector<int> ans = sol.largestDivisibleSubset(nums);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
