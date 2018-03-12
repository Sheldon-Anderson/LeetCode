#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
		// Exceptional Case: 
		if(n == 0){
			return "";
		}
		if(n == 1){
			return strs[0];
		}
		int min_len = INT_MAX;
		for(string str: strs){
			min_len = min(min_len, (int)(str.length()));
		}
		for(int i = min_len; i >= 1; i--){
			string prefix = strs[0].substr(0, i);
			bool flag = false;
			for(int j = 1; j <= n - 1; j++){
				if(strs[j].substr(0, i) != prefix){
					flag = true;
					break;
				}
			}
			if(!flag){
				return prefix;
			}
		}
		return "";
    }
};

int main(){
	Solution sol;
	vector<string> strs = {"abc", "abcd", "adcde", "cbddef"};
	cout << "ans: " << sol.longestCommonPrefix(strs) << endl;
	return 0;
}
