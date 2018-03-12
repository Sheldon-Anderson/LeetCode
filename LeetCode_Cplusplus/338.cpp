#include <bits/stdc++.h>
using namespace std;

// dynamic programming
class Solution {
public:
    vector<int> countBits(int num) {
        if(num == 0){
			return vector<int>{0};
		}
		if(num == 1){
			return vector<int>{0, 1};
		}
		// create and init
		vector<int> dp(num + 1);
		dp[0] = 0;
		dp[1] = 1;
		// DP
		int base = 2;
		while(base <= num){
			dp[base] = 1;
			for(int i = base + 1; i <= min(num, (base << 1) - 1); i++){
				dp[i] = dp[base] + dp[i - base];
			}
			base <<= 1;
		}
		return dp;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		vector<int> ans = sol.countBits(num);
		// console output
		for(int val: ans){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
