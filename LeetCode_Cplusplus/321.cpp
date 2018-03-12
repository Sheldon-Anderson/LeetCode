#include <bits/stdc++.h>
using namespace std;

// merge
class Solution {
private: 
	// pick out cnt numbers from nums to form the max number
	vector<int> getMaxNumber(vector<int>& nums, int n, int cnt){
		vector<int> vec;
		int start = 0, pos;
		for(int i = cnt; i >= 1; i--){
			int j = start;
			pos = start;
			while(j <= n - i){
				if(nums[j] > nums[pos]){
					pos = j;
				}
				j++;
			}
			vec.push_back(nums[pos]);
			start = pos + 1;
		}
		return vec;
	}
	
	// compare ans1 and ans2
	bool cmp(vector<int> &ans1, vector<int> &ans2, int s1, int e1, int s2, int e2){
		while(s1 <= e1 && s2 <= e2){
			if(ans1[s1] > ans2[s2]){
				return true;
			}
			else if(ans1[s1] < ans2[s2]){
				return false;
			}
			s1++;
			s2++;
		}
		return s1 != (e1 + 1);
	}

public: 
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int n1 = nums1.size(), n2 = nums2.size();
		// Exceptional Case: 
		if(n1 + n2 < k || k <= 0){
			return vector<int>();
		}
		vector<int> ans(k, 0);
		int L = max(0, k - n2);
		int R = min(k, n1);
		for(int i = L; i <= R; i++){
			vector<int> ans1 = getMaxNumber(nums1, n1, i);
			vector<int> ans2 = getMaxNumber(nums2, n2, k - i);
			// merge into the max number
			vector<int> res;
			int c1 = 0, c2 = 0;
			while(c1 <= i - 1 && c2 <= k - i - 1){
				if(cmp(ans1, ans2, c1, i - 1, c2, k - i - 1)){
					res.push_back(ans1[c1++]);
				}
				else{
					res.push_back(ans2[c2++]);
				}
			}
			while(c1 <= i - 1){
				res.push_back(ans1[c1++]);
			}
			while(c2 <= k - i - 1){
				res.push_back(ans2[c2++]);
			}
			if(cmp(res, ans, 0, k - 1, 0, k - 1)){
				ans = res;
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums1 = {2,5,6,4,4,0};
	vector<int> nums2 = {7,3,8,0,6,5,7,6,2};
	int k = 15;
	vector<int> ans = sol.maxNumber(nums1, nums2, k);
	//console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
