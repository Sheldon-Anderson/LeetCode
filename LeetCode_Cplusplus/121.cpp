#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
		if(n <= 1){
			return 0;
		}
		int min_price = prices[0], max_profit = 0;
		for(int i = 1; i <= n - 1; i++){
			if(prices[i] < min_price){
				min_price = prices[i];
			}
			else if(prices[i] > min_price){
				max_profit = max(max_profit, prices[i] - min_price);
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
