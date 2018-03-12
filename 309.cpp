#include <bits/stdc++.h>
using namespace std;

/*
// dynamic programming
// Accepted
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if(n == 0){
			return 0;
		}
		// create and init
		int *buy = new int[n];
		int *sell = new int[n];
		int *cool = new int[n];
		buy[0] = -prices[0];
		sell[0] = 0;
		cool[0] = 0;
		// DP
		for(int i = 1; i <= n - 1; i++){
			buy[i] = max(cool[i - 1] - prices[i], buy[i - 1]);
			sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
			cool[i] = max(buy[i - 1], max(sell[i - 1], cool[i - 1]));
		}
		// get answer
		// obviously, buy[i] <= cool[i] <= sell[i]
		return sell[n - 1];
    }
};
*/

/*
// dynamic programming
// Accepted
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n == 0){
			return 0;
		}
		// create and init
		int *buy = new int[n];
		int *sell = new int[n];
		buy[0] = -prices[0];
		sell[0] = 0;
		// DP
		for(int i = 1; i <= n - 1; i++){
			buy[i] = max((i == 1? 0: sell[i - 2]) - prices[i], buy[i - 1]);
			sell[i] = max(buy[i - 1] + prices[i], sell[i - 1]);
		}
		return sell[n - 1];
	}
};
*/

// State Machine
class Solution {
public:
    int maxProfit(vector<int>& prices) {
		int n = prices.size();
		if(n == 0){
			return 0;
		}
		// create and init
		int *s0 = new int[n];
		int *s1 = new int[n];
		int *s2 = new int[n];
		s0[0] = 0;
		s1[0] = -prices[0];
		s2[0] = INT_MIN;
		// DP
		for(int i = 1; i <= n - 1; i++){
			s0[i] = max(s0[i - 1], s2[i - 1]);
			s1[i] = max(s0[i - 1] - prices[i], s1[i - 1]);
			s2[i] = s1[i - 1] + prices[i];
		}
		// ge answer
		return max(s0[n - 1], s2[n - 1]);
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> prices = {1, 2, 3, 0, 2};
	cout << "ans: " << sol.maxProfit(prices) << endl;
	return 0;
}
