#include<bits/stdc++.h>

using namespace std;

// DFS
class Solution {
private: 
	bool DFS(vector<int>& nums, int n, int side, int k, vector<int> vec){
		// Exceptional Case: 
		if(k == n){
			if(side == vec[0] && side == vec[1] && side == vec[2]){
				return true;
			}
			return false;
		}
		// set
		set<int> s;
		for(int i = 0; i <= 3; i++){
			if(vec[i] + nums[k] <= side && !s.count(vec[i])){
			    s.insert(vec[i]);
				vec[i] += nums[k];
				if(DFS(nums, n, side, k + 1, vec)){
					return true;
				}
				vec[i] -= nums[k];
			}
		}
		return false;
	}

public:
    bool makesquare(vector<int>& nums) {
        int n = nums.size();
		// Exceptional Case: 
		if(n <= 3){
			return false;
		}
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if(sum % 4){
			return false;
		}
		return DFS(nums, n, sum / 4, 0, vector<int>(4, 0));
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {3, 3, 3, 3, 4};	// {1, 1, 2, 2, 2};
	cout << "ans: " << sol.makesquare(nums) << endl;
	return 0;
}
