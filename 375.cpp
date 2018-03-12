#include <bits/stdc++.h>
using namespace std;

/*
// minimax: DFS + memory
// Accepted
class Solution {
private: 
	int **dp;
	
	int DFS(int left, int right){
		if(left >= right){
			return 0;
		}
		if(dp[left][right] > 0){
			return dp[left][right];
		}
		// get minimax
		int minimax = INT_MAX;
		for(int i = left; i <= right; i++){
			minimax = min(minimax, i + max(DFS(left, i - 1), DFS(i + 1, right)));
		}
		// return minimax
		dp[left][right] = minimax;
		return minimax;
	}
	
public:
    int getMoneyAmount(int n) {
		// create and init
		dp = new int*[n + 1];
		for(int i = 0; i <= n; i++){
			dp[i] = new int[n + 1];
			memset(dp[i], 0, sizeof(int) * (n + 1));
		}
		// DFS
		return DFS(1, n);
    }
};
*/

// dynamic programming
class Solution{
public:
    int getMoneyAmount(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		// DP
		for(int step = 1; step <= n - 1; step++){
			for(int start = 1; start <= n - step; start++){
				int end = start + step;
				int minimax = INT_MAX;			
				for(int i = start + 1; i <= end - 1; i++){
					minimax = min(minimax, i + max(dp[start][i - 1], dp[i + 1][end]));
				}
				minimax = min(minimax, start + dp[start + 1][end]);
				minimax = min(minimax, end + dp[start][end - 1]);
				dp[start][end] = minimax;			
			}
		}
		// get answer
		return dp[1][n];
	}
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.getMoneyAmount(n) << endl;
	}
	return 0;
}
