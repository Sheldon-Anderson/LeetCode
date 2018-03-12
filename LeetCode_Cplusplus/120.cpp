#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		int m = triangle.size();
		if(m == 0){
			return 0;
		}
		if(m == 1){
			return triangle[0][0];
		}
		// init
		vector<int> ans(m, 0);
		ans[0] = triangle[0][0];
		// dp
		for(int i = 1; i <= m - 1; i++){
			vector<int> pre = ans;
			for(int j = 0; j <= i; j++){
				if(j == 0){
					ans[j] = triangle[i][j] + pre[0];
				}
				else if(j == i){
					ans[j] = triangle[i][j] + pre[j - 1];
				}
				else{
					ans[j] = triangle[i][j] + min(pre[j - 1], pre[j]);
				}
			}
		}
		// get answer
		int sum = INT_MAX;
		for(int val: ans){
			sum = min(sum, val);
		}
		return sum;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> triangle = {
		{2},
		{3, 4},
		{6, 5, 7},
		{4, 1, 8, 3}
	};
	cout << "sum: " << sol.minimumTotal(triangle) << endl;
	return 0;
}
