#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length();
		// Exceptional Case: 
		if(n == 0){
			return 0;
		}
		int left = 0, right = 0, ans = 0;
		set<char> ss;
		while(left <= right && right <= n - 1){
			// debug
			// cout << "l: " << left << ", r: " << right << endl;
			if(ss.count(s[right])){
				ans = max(ans, right - left);
				ss.erase(s[left]);
				left++;
			}
			else{
				ss.insert(s[right]);
				right++;
				if(right == n){
					ans = max(ans, n - left);
				}
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.lengthOfLongestSubstring(s) << endl;
	}
	return 0;
}
