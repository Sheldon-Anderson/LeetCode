#include<bits/stdc++.h>
using namespace std;

// greedy
// scan from left to right and from right to left
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
		if(n == 0){
			return 0;
		}
		int ans = 0;
		vector<int> candies(n, 1);
		// scan from left to right: 1 -> n - 1
		for(int i = 1; i <= n - 1; i++){
			if(ratings[i] > ratings[i - 1]){
				candies[i] = candies[i - 1] + 1;
			}
		}
		// scan from right to left: n - 2 -> 0
		for(int i = n - 2; i >= 0; i --){
			if(ratings[i] > ratings[i + 1] && candies[i] < candies[i + 1] + 1){
				candies[i] = candies[i + 1] + 1;
			}
		}
		// get answer
		for(int val: candies){
			ans += val;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> ratings = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5};
	cout << "ans: " << sol.candy(ratings) << endl;
	return 0;
}
