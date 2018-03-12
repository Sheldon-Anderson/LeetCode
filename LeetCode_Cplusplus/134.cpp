#include<bits/stdc++.h>
using namespace std;

// greedy
/*
	1. If ∑(gas[i] - cost[i]) >= 0, i from 0 to n - 1, then there exists a solution. 
	2. Suppose we have ∑(gas[i] - cost[i]) is the smallest, i from 0 to k, 
		then we get k + 1 is a valid start for solution. 
*/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
		if(n == 0){
			return -1;
		}
		if(n == 1){
			return gas[0] >= cost[0]? 0: -1;
		}
		int delta_sum = 0, min_sum = INT_MAX;
		int pos = -1;
		for(int i = 0; i <= n - 1; i++){
			delta_sum += (gas[i] - cost[i]);
			if(delta_sum < min_sum){
				min_sum = delta_sum;
				pos = i;
			}
		}
		return (delta_sum >= 0 && pos != -1)? (pos + 1) % n: -1;
    }
};

int main(){
	Solution sol;
	vector<int> gas = {5};
	vector<int> cost = {5};
	cout << "ans: " << sol.canCompleteCircuit(gas, cost) << endl;
	return 0;
}
