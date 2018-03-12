#include<bits/stdc++.h>

using namespace std;

// Dynamic Programming
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        int n = p.length();
		if(n <= 1){
			return n;
		}
		// create and init
		vector<int> dp(n, 1);
		vector<int> count(26, 0);
		// DP
		count[p[0] - 'a'] = 1;
		for(int i = 1; i <= n - 1; i++){
			if(p[i - 1] + 1 == p[i] || p[i - 1] == p[i] + 25){
				dp[i] += dp[i - 1];
			}
			if(dp[i] > count[p[i] - 'a']){
				count[p[i] - 'a'] = dp[i];
			}
		}
		// get answer
		return accumulate(count.begin(), count.end(), 0);
    }
};

int main(int argc, char** argv){
	Solution sol;
	string p;
	while(cin >> p){
		cout << "ans: " << sol.findSubstringInWraproundString(p) << endl;
	}
	return 0;
}
