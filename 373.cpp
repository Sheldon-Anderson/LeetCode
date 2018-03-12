#include <bits/stdc++.h>

using namespace std;

// priority_queue
class Solution {
private: 
	// priority_queue: ascending order
	struct cmp{
		bool operator()(const pair<int, int> &a, const pair<int, int> &b)const{
			return a.first + a.second > b.first + b.second;
		}
	};

public:
    vector<pair<int, int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
		vector<pair<int, int>> ans;
		// Exceptional Case: 
		if(k == 0){
			ans;
		}
        int n1 = nums1.size(), n2 = nums2.size();
		if(n1 == 0 || n2 == 0){
			return ans;
		}
		// priority_queue
		priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
		for(int i = 0; i <= n1 - 1; i++){
			for(int j = 0; j <= n2 - 1; j++){
				pq.push(make_pair(nums1[i], nums2[j]));
				if(pq.size() > max(0, n1 * n2 - k)){
					ans.push_back(pq.top());
					pq.pop();
				}
			}
		}
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums1 = {1, 2}, nums2 = {3};
	int k = 3;
	vector<pair<int, int>> ans = sol.kSmallestPairs(nums1, nums2, k);
	// console output
	for(auto &p: ans){
		cout << p.first << ", " << p.second << endl;
	}
	return 0;
}
