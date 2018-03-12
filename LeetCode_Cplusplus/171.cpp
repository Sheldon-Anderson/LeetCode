#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        int n = s.length();
		if(n == 0){
			return 0;
		}
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			ans = 26 * ans + (s[i] - 'A' + 1);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.titleToNumber(s) << endl;
	}
	return 0;
}
