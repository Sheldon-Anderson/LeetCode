#include<bits/stdc++.h>

using namespace std;

// binary search
class Solution {
private: 
	int binary_search(vector<int> &vec, int left, int right, int target){
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(vec[mid] < target){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return left;
	}

public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
		vector<int> vec;
		vector<double> ans;
		for(int i = 0; i <= n - 1; i++){
			// insert
			int pos = binary_search(vec, 0, vec.size() - 1, nums[i]);
			vec.insert(vec.begin() + pos, nums[i]);
			// delete
			if(i >= k){
				auto itv = find(vec.begin(), vec.end(), nums[i - k]);
				vec.erase(itv);
			}
			if(i >= k - 1){
				if(k & 1){
					ans.push_back(vec[k / 2]);
				}
				else{
					ans.push_back((1.0 * vec[k / 2 - 1] + 1.0 * vec[k / 2]) / 2.0);
				}
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {2147483647, 2147483647};
	int k = 2;
	vector<double> ans = sol.medianSlidingWindow(nums, k);
	// console output
	for(double val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
