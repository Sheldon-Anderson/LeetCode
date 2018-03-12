#include <bits/stdc++.h>
using namespace std;

/*
// set_intersection
// Accepted
class Solution {
private: 
	static int cmp(const int &a, const int &b){
		return a < b;
	}

public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		// sort
        sort(nums1.begin(), nums1.end());
		sort(nums2.begin(), nums2.end());
		// get answer
		vector<int> res, ans;
		set_intersection(nums1.begin(), nums1.end(), nums2.begin(), nums2.end(), inserter(res, res.begin()));
		// unique
		auto start = res.begin(), end = unique(res.begin(), res.end());
		while(start != end){
			ans.push_back(*start);
			start++;
		}
		return ans;
    }
};
*/

// set_intersection
class Solution{
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		set<int> s1, s2;
		// copy vector to set
		for(int v1: nums1){
			s1.insert(v1);
		}
		for(int v2: nums2){
			s2.insert(v2);
		}
		// get answer
		set<int> s3;
		vector<int> ans;
		set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(s3, s3.begin()));
		// copy set to vector
		copy(s3.begin(), s3.end(), back_inserter(ans));
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2};
	vector<int> ans = sol.intersection(nums1, nums2);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
