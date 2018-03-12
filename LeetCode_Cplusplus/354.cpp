#include <bits/stdc++.h>
using namespace std;

/*
// sort + Dynamic programming
// Accepted
class Solution {
private: 
	// sort compare function
	static int cmp(const pair<int, int> &a, const pair<int, int> &b){
		if(a.first != b.first){
			return a.first < b.first;
		}
		return a.second < b.second;
	}

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
		if(n <= 1){
			return n;
		}
		//sort
		sort(envelopes.begin(), envelopes.end(), cmp);
		// create and init
		int *dp = new int [n];
		for(int i = 0; i <= n - 1; i++){
			dp[i] = 1;
		}
		// DP
		for(int i = 1; i <= n - 1; i++){
			for(int j = 0; j <= i - 1; j++){
				if(envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second){
					dp[i] = max(dp[i], dp[j] + 1);
				}
			}
		}
		// get answer
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			ans = max(ans, dp[i]);
		}
		return ans;
    }
};
*/

// sort + LIS Algorithm
class Solution{
private: 
	
	// sort compare function
	static int cmp(const pair<int, int> &a, const pair<int, int> &b){
		if(a.first != b.first){
			return a.first < b.first;
		}
		return a.second > b.second;
	}

	// binary search function for LIS
	int binary_search(vector<int> &B, int target){
		int left = 0, right = B.size() - 1;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			if(target > B[mid]){
				left = mid + 1;
			}
			else if(target <= B[mid]){
				right = mid - 1;
			}
		}
		return left;
	}

public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
		int n = envelopes.size();
		if(n <= 1){
			return n;
		}
		// sort
		sort(envelopes.begin(), envelopes.end(), cmp);
		// create and init
		vector<int> B;
		B.push_back(envelopes[0].second);
		int Len = 1;
		// LIS
		for(int i = 1; i <= n - 1; i++){
			if(envelopes[i].second > B[Len - 1]){
				B.push_back(envelopes[i].second);
				Len++;
			}
			else{
				// find the first pos that B[pos] >= envelopes[i].second
				int pos = binary_search(B, envelopes[i].second);
				B[pos] = envelopes[i].second;
			}
		}
		// get answer
		return Len;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<pair<int, int>> envelopes = {{2,100},{3,200},{4,300},{5,500},{5,400},{5,250},{6,370},{6,360},{7,380}};
	cout << "ans: " << sol.maxEnvelopes(envelopes) << endl;
	return 0;
}
