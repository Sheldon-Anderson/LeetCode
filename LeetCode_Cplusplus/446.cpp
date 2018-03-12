#include<bits/stdc++.h>

using namespace std;

#define LL long long
/*
	for example: 
	{2,		4,		6,		8,		10}
			2-1		4-1		6-1		8-1
					2-2		4-1		6-1
							2-3		4-2
									2-4
	ans = 1 + 2 + 1 + 3 = 7
*/
// Dynamic Programming + unordered_map
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
		if(n <= 2){
			return 0;
		}
		// create
		// map<int, int> *dp = new map<int, int>[n];	// Memory Limit Exceeded 
		unordered_map<int, int> *dp = new unordered_map<int, int>[n];
		// DP
		int ans = 0;
		for(int i = 1; i <= n - 1; i++){
			for(int j = 0; j <= i - 1; j++){
				LL D = (LL)A[i] - (LL)A[j];
				if(D < INT_MIN || D > INT_MAX){
					continue;
				}
				int delta = (int)D;
				dp[i][delta]++;
				if(dp[j].count(delta)){
					dp[i][delta] += dp[j][delta];
					ans += dp[j][delta];
				}
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> A = {2, 4, 6, 8, 10};
	cout << "ans: " << sol.numberOfArithmeticSlices(A) << endl;
	return 0;
}
