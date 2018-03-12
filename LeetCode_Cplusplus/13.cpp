#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
		// Exceptional Case: 
		int n = s.length();
		if(n == 0){
			return 0;
		}
        map<char, int> m;
		m['M'] = 1000;
		m['D'] = 500;
		m['C'] = 100;
		m['L'] = 50;
		m['X'] = 10;
		m['V'] = 5;
		m['I'] = 1;
		int ans = 0;
		for(int i = 0; i <= n - 2; i++){
			ans += (m[s[i]] < m[s[i + 1]]? -m[s[i]]: m[s[i]]);
		}
		ans += m[s[n - 1]];
		return ans;
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		cout << sol.romanToInt(s) << endl;
	}
	return 0;
}
