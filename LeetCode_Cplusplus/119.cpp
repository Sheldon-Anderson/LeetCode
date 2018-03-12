#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0){
			return vector<int>();
		}
		vector<int> ans(rowIndex + 1, 1);
		if(rowIndex <= 1){
			return ans;
		}
		vector<int> pre(rowIndex + 1, 1);
		for(int i = 2; i <= rowIndex; i++){
			for(int j = 1; j <= i - 1; j++){
				ans[j] = pre[j - 1] + pre[j];
			}
			pre = ans;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	int rowIndex;
	while(cin >> rowIndex){
		vector<int> ans = sol.getRow(rowIndex);
		// console output
		for(int val: ans){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
