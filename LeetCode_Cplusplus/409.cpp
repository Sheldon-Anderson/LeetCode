#include<bits/stdc++.h>

using namespace std;

// map
class Solution {
public:
    int longestPalindrome(string s) {
		int n = s.length();
		if(n <= 1){
			return n;
		}
		int ans = 0;
		// map
		map<char, int> m;
		for(char c: s){
			m[c]++;
		}
		// check odd
		bool odd = false;
		for(auto p: m){
			if(p.second & 1){
				odd = true;
				ans += (p.second - 1);
			}
			else{
				ans += p.second;
			}
		}
		// get answer
		if(odd){
			ans += 1;
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.longestPalindrome(s) << endl;
	}
	return 0;
}
