#include<bits/stdc++.h>

using namespace std;

// dynamic programming
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size();
		if(n <= 2){
			return 0;
		}
		// create and init
		int *dp = new int[n];
		dp[0] = 1;
		dp[1] = 2;
		for(int i = 2; i <= n - 1; i++){
			if(A[i] - A[i - 1] == A[i - 1] - A[i - 2]){
				dp[i] = dp[i - 1] + 1;
			}
			else{
				dp[i] = 2;
			}
		}
		// get answer
		int ans = 0;
		for(int i = 2; i <= n - 1; i++){
			ans += (dp[i] - 2);
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> A = {1, 2, 3, 4};
	cout << "ans: " << sol.numberOfArithmeticSlices(A) << endl;
	return 0;
}
