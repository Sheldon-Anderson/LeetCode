#include<bits/stdc++.h>

using namespace std;

/*
// dynamic programming
// Accepted
class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
		// create and init
		set<int> *dp = new set<int>[n];
		dp[0].insert(0);
		// DP
		for(int i = 0; i <= n - 2; i++){
			for(int step: dp[i]){
				for(int j = i + 1; j <= n - 1; j++){
					if(step - 1 >= 1 && stones[j] - stones[i] == step - 1){
						dp[j].insert(step - 1);
					}
					else if(stones[j] - stones[i] == step){
						dp[j].insert(step);
					}
					else if(stones[j] - stones[i] == step + 1){
						dp[j].insert(step + 1);
					}
					else if(stones[j] - stones[i] > step + 1){
						break;
					}
				}
			}
		}
		// get answer
		return dp[n - 1].size() != 0;
    }
};
*/

// dynamic programming
class Solution {
public:
    bool canCross(vector<int>& stones) {
		int n = stones.size();
		// create and init
		set<int> *dp = new set<int>[n];
		dp[0].insert(0);
		// DP
		for(int i = 0; i <= n - 2; i++){
			for(int step: dp[i]){
				for(int j = i + 1; j <= n - 1; j++){
					int delta = stones[j] - stones[i];
					if(delta >= step - 1 && delta <= step + 1){
						// check
						if(j == n - 1){
							return true;
						}						
						dp[j].insert(delta);
					}
					else if(delta > step + 1){
						break;
					}
				}
			}
		}
		// get answer
		return dp[n - 1].size() != 0;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};	// {0, 1, 2, 3, 4, 8, 9, 11};
	cout << "ans: " << sol.canCross(stones) << endl;
	return 0;
}
