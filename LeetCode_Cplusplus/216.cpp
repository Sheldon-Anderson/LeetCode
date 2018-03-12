#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
private: 
	vector<vector<int>> ans;
	vector<int> res;

	void DFS(int n, int k, int cnt, int digit, int sum){
		if(cnt == k && sum == n){
			ans.push_back(res);
			return;
		}
		if(cnt >= k || sum >= n){
			return;
		}
		//  given that only numbers from 1 to 9 can be used
		for(int i = digit + 1; i <= min(9, n - sum); i++){
			res.push_back(i);
			DFS(n, k, cnt + 1, i, sum + i);
			res.pop_back();
		}
	}

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        ans.clear();
		res.clear();
		if(k <= 0 || n <= 0){
			return ans;
		}
		DFS(n, k, 0, 0, 0);
		return ans;
    }
};

int main(){
	Solution sol;
	int k, n;
	while(cin >> k >> n){
		vector<vector<int>> ans = sol.combinationSum3(k, n);
		// console output
		for(auto &p: ans){
			for(int val: p){
				cout << val << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
