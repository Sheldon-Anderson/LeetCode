#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        if(dungeon.empty()){
			return -1;
		}
		int m = dungeon.size(), n = dungeon[0].size();
		// create and init
		vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
		dp[m - 1][n - 1] = dungeon[m - 1][n - 1] > 0? 1: 1 - dungeon[m - 1][n - 1];
		// dp
		for(int i = m - 1; i >= 0; i--){
			for(int j = n - 1; j >= 0; j--){
				if(i - 1 >= 0){
					dp[i - 1][j] = min(dp[i - 1][j], (dp[i][j] > dungeon[i - 1][j]? dp[i][j] - dungeon[i - 1][j]: 1));
				}
				if(j - 1 >= 0){
					dp[i][j - 1] = min(dp[i][j - 1], (dp[i][j] > dungeon[i][j - 1]? dp[i][j] - dungeon[i][j - 1]: 1));
				}
			}
		}
		// get answer
		return dp[0][0];
    }
};

int main(){
	Solution sol;
	vector<vector<int>> dungeon = {
		{-2, -3, 3},
		{-5, -10, 1},
		{10, 30, -5}
	};
	cout << "ans: " << sol.calculateMinimumHP(dungeon) << endl;
	return 0;
}
