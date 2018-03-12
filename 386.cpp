#include <bits/stdc++.h>
using namespace std;

/*
// DFS
// Accepted
class Solution {
private: 
	vector<int> ans;
	
	void DFS(int n, int digit){
		ans.push_back(digit);
		if(ans.size() == n){
			return;
		}
		if(digit * 10 <= n){
			DFS(n, digit * 10);
		}
		if(digit + 1 <= n && digit % 10 != 9){
			DFS(n, digit + 1);
		}
	}

public:
    vector<int> lexicalOrder(int n) {
        if(n <= 0){
			return vector<int>();
		}
		ans.clear();
		DFS(n, 1);
		return ans;
    }
};
*/

class Solution{
public:
    vector<int> lexicalOrder(int n) {
		if(n <= 0){
			return vector<int>();
		}
		vector<int> ans(n);
		int digit = 1;
		for(int i = 0; i <= n - 1; i++){
			ans[i] = digit;
			if(digit * 10 <= n){
				digit *= 10;
			}
			else{
				if(digit >= n){
					digit /= 10;
				}
				digit += 1;
				while(!(digit % 10)){
					digit /= 10;
				}
			}
		}
		return ans;
	}
};

int main(int argc, char**){
	Solution sol;
	int n;
	while(cin >> n){
		vector<int> ans = sol.lexicalOrder(n);
		// console output
		for(int val: ans){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
