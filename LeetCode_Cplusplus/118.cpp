#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
		if(numRows == 0){
			return ans;
		}
		ans.push_back(vector<int>(1, 1));
		if(numRows == 1){
			return ans;
		}
		for(int i = 1; i <= numRows - 1; i++){
			vector<int> res(i + 1, 1);
			for(int j = 1; j <= i - 1; j++){
				res[j] = ans[i - 1][j - 1] + ans[i - 1][j];
			}
			ans.push_back(res);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	int numRows;
	while(cin >> numRows){
		vector<vector<int>> ans = sol.generate(numRows);
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
