#include<bits/stdc++.h>
using namespace std;

// Manacher's Algorithm
// T(n) = O(n)
class Solution {
public:
    string shortestPalindrome(string s) {
		int n = s.length();
		// Exceptional Case: 
		if(n <= 1){
			return s;
		}
		// s -> t, "abba" -> "^#a#b#b#a#$"
		string t = "^";
		for(int i = 0; i <= n - 1; i++){
			t += ("#" + s.substr(i , 1));
		}
		t += "#$";
		// update the center and the right side R
		int nn = t.length();
		int center = 0, R = 0;
		int *p = new int[nn];
		memset(p, 0, sizeof(int) * nn);
		for(int i = 1; i <= nn - 2; i++){
			p[i] = (R > i)? min(p[2 * center - i], R - i): 0;
			while(t[i + p[i] + 1] == t[i - p[i] - 1]){
				p[i]++;
			}
			if(i + p[i] > R){
				center = i;
				R = i + p[i];
			}
		}
		// find the max radius
		int centerIndex = 0, radius = 0;
		for(int i = 0; i <= nn / 2; i++){
			// p[i] == i - 1 make sure that the start index is 0 in string s
			if(p[i] > radius && p[i] == i - 1){
				radius = p[i];
				centerIndex = i;
			}
		}
		// get answer
		if(radius == n){
			return s;
		}
		string str = s.substr(radius, n - radius);
		reverse(str.begin(), str.end());
		return str + s;
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.shortestPalindrome(s) << endl;
	}
	return 0;
}
