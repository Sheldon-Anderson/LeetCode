#include<bits/stdc++.h>
using namespace std;

// greedy
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if(n <= 1){
			return 0;
		}
		int max_profit = 0;
		for(int i = 1; i <= n - 1; i++){
			if(prices[i] > prices[i - 1]){
				max_profit += (prices[i] - prices[i - 1]);
			}
		}
		return max_profit;
    }
};

int main(){
	Solution sol;
	vector<int> prices = {7, 1, 5, 3, 6, 4};
	cout << "ans: " << sol.maxProfit(prices) << endl;
	return 0;
}
