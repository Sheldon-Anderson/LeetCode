#include<bits/stdc++.h>
using namespace std;

/*
// find k smallest element algorithm: DFS
// T(m, n) = O(log(m + n))
class Solution {
private: 
	// g++ -std=c++14 4.cpp -o 4.exe could compile successfully
	// double findKSmall(auto s1, auto s2, int n1, int n2, int k){

	typedef vector<int>	::iterator Iter;
	
	double findKSmall(Iter s1, Iter s2, int n1, int n2, int k){
		// Exceptional Case: 
		if(n1 > n2){
			return findKSmall(s2, s1, n2, n1, k);
		}
		if(n1 == 0){
			return *(s2 + k - 1);
		}
		if(k == 1){
			return min(*s1, *s2);
		}
		int t1 = min(k / 2, n1);
		int t2 = k - t1;
		// delete t1 or t2 elements
		double ans = -1.0;
		if(*(s1 + t1 - 1) < *(s2 + t2 - 1)){
			ans = findKSmall(s1 + t1, s2, n1 - t1, n2, k - t1);
		}
		else if(*(s1 + t1 - 1) > *(s2 + t2 - 1)){
			ans = findKSmall(s1, s2 + t2, n1, n2 - t2, k - t2);
		}
		else{
			ans = *(s1 + t1 - 1);
		}
		return ans;
	}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
		auto s1 = nums1.begin(), s2 = nums2.begin();
		double ans = -1.0;
		// odd
		if((n1 + n2) & 1){
			ans = findKSmall(s1, s2, n1, n2, (n1 + n2) / 2 + 1);
		}
		// even
		else{
			ans = (findKSmall(s1, s2, n1, n2, (n1 + n2) / 2) + findKSmall(s1, s2, n1, n2, (n1 + n2) / 2 + 1)) / 2.0;
		}
		return ans;
    }
};
*/

// find k smallest element algorithm: binary search
// T(m, n) = O(min(m, n))
class Solution{
private: 
	// find the first pos that vec[pos] > target
	// the same function as: upper_bound(vec.begin(), vec.end(), target)
	int binary_search(vector<int>& vec, int target){
		int l = 0, r = vec.size() - 1;
		while(l <= r){
			// debug
			// cout << "l: " << l << ", r: " << r << endl;
			int m = (l + r) >> 1;
			if(vec[m] > target){
				r = m - 1;
			}
			else if(vec[m] <= target){
				l = m + 1;
			}
		}
		return l;
	}
	
	double findKSmall(vector<int>& nums1, vector<int>& nums2, int k){
		int n1 = nums1.size(), n2 = nums2.size();
		int left = min(nums1[0], nums2[0]);
		int right = max(nums1[n1 - 1], nums2[n2 - 1]);
		// binary search
		while(left <= right){
			// debug
			// cout << "left: " << left << ", right: " << right << endl;
			int mid = (left + right) >> 1;
			int k1 = binary_search(nums1, mid);
			int k2 = binary_search(nums2, mid);
			// debug
			// cout << "k1: " << k1 << ", k2: " << k2 << ", k: " << k << endl;
			if(k1 + k2 == k){
				if(k1 > 0 && nums1[k1 - 1] == mid){
					return mid;
				}
				else if(k2 > 0 && nums2[k2 - 1] == mid){
					return mid;
				}
				else{
					right = mid - 1;
				}
			}
			else if(k1 + k2 > k){
				right = mid - 1;
			}
			else if(k1 + k2 < k){
				left = mid + 1;
			}
		}
		return left;
	}

public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int n1 = nums1.size(), n2 = nums2.size();
		// Exceptional Case: 
		if(n1 == 0 && n2 == 0){
			return 0.0;
		}
		else if(n1 == 0 && n2 != 0){
			if(n2 & 1){
				return (double)nums2[n2 / 2];
			}
			else{
				return ((double)nums2[n2 / 2 - 1] + (double)nums2[n2 / 2]) / 2.0;
			}
		}
		else if(n1 != 0 && n2 == 0){
			if(n1 & 1){
				return (double)nums1[n1 / 2];
			}
			else{
				return ((double)nums1[n1 / 2 - 1] + (double)nums1[n1 / 2]) / 2.0;
			}
		}
		double ans = 0.0;
		if((n1 + n2) & 1){
			ans = findKSmall(nums1, nums2, (n1 + n2) / 2 + 1);
		}
		else{
			ans = (findKSmall(nums1, nums2, (n1 + n2) / 2) + findKSmall(nums1, nums2, (n1 + n2) / 2 + 1)) / 2.0;
		}
		return ans;
	}
};

int main(){
	Solution sol;
	vector<int> nums1 = {100001}, nums2 = {100000};
	cout << "ans: " << sol.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}
