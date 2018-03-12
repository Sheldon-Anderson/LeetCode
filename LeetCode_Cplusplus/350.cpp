#include <bits/stdc++.h>
using namespace std;

// set_intersection
class Solution {
private: 
	static int cmp(const int &a, const int &b){
		return a < b;
	}

public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		// sort
        sort(nums1.begin(), nums1.end(), cmp);
		sort(nums2.begin(), nums2.end(), cmp);
		// set_intersection
		vector<int> ans;
		set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), inserter(ans, ans.begin()));
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
	vector<int> ans = sol.intersect(nums1, nums2);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
