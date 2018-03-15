#include<bits/stdc++.h>
using namespace std;

// Manacher's Algorithm
// T(n) = O(n)
class Solution {
public:
    string longestPalindrome(string s) {
		int n = s.length();
		// Exceptional Case: 
        if(n <= 1){
			return s;
		}
		// s -> t: "abba" -> "^#a#b#b#a#$"
		string t = "^";
		for(int i = 0; i <= n - 1; i++){
			t += ("#" + s.substr(i, 1));
		}
		t += "#$";
		// update the center and the right side R
		n = t.length();
		int center = 0, R = 0;
		int *p = new int[n];
		memset(p, 0, sizeof(int) * n);
		for(int i = 0; i <= n - 2; i++){
			p[i] = R > i? min(p[2 * center - i], R - i): 0;
			while(t[i + p[i] + 1] == t[i - p[i] - 1]){
				p[i]++;
			}
			if(i + p[i] > R){
				center = i;
				R = i + p[i];
			}
		}
		// find the maximum element in P
		center = R = 0;
		for(int i = 0; i <= n - 2; i++){
			if(p[i] > R){
				R = p[i];
				center = i;
			}
		}
		// get longest palindrome
		return s.substr((center - R - 1) / 2, R);
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.longestPalindrome(s) << endl;
	}
	return 0;
}
