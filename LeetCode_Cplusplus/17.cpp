#include<bits/stdc++.h>
using namespace std;

class Solution {
private: 
	string str[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
	vector<string> ans;

	void DFS(string &digits, string res, int n, int k){
		// Exceptional Case: 
		if(k == n){
			ans.push_back(res);
			return;
		}
		int len = str[digits[k] - '0'].length();
		for(int i = 0; i <= len - 1; i++){
			DFS(digits, res + str[digits[k] - '0'].substr(i, 1), n, k + 1);
		}
	}

public:
    vector<string> letterCombinations(string digits) {
		int n = digits.length();
		// Exceptional Case: 
		if(n == 0){
			return vector<string>();
		}
		// check if the digits contain 0 or 1
		for(int i = 0; i <= n - 1; i++){
			if(!(digits[i] >= '2' && digits[i] <= '9')){
				return vector<string>();
			}
		}
		// DFS get answers
		ans.clear();
		DFS(digits, "", n, 0);
		return ans;
    }
};

int main(){
	Solution sol;
	string digits;
	while(cin >> digits){
		vector<string> ans = sol.letterCombinations(digits);
		//console output
		for(string s: ans){
			cout << s << " ";
		}
		cout << endl;		
	}
	return 0;
}
