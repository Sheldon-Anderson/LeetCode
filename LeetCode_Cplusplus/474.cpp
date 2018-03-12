#include<bits/stdc++.h>

using namespace std;

// Dynamic Programming
// two dimension 0-1 knapsack problem
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
		int N = strs.size();
        if(!N){
			return 0;
		}
		// create and init
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		vector<pair<int, int>> vec;
		for(string s: strs){
			int cnt_zeros = 0, cnt_ones = 0;
			for(char c: s){
				if(c == '1'){
					cnt_ones++;
				}
				else if(c == '0'){
					cnt_zeros++;
				}
			}
			vec.push_back(make_pair(cnt_zeros, cnt_ones));
		}
		// DP
		for(int i = 0; i <= N - 1; i++){
			for(int j = m; j >= vec[i].first; j--){
				for(int k = n; k >= vec[i].second; k--){
					dp[j][k] = max(dp[j][k], dp[j - vec[i].first][k - vec[i].second] + 1);
				}
			}
		}
		// get answer
		return dp[m][n];
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<string> strs = {"10", "0", "1"};	// {"10", "0001", "111001", "1", "0"};
	int m = 1, n = 1;
	cout << "ans: " << sol.findMaxForm(strs, m, n) << endl;
	return 0;
}
