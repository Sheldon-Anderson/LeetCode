#include <bits/stdc++.h>
using namespace std;

// divide and conquer + count
class Solution {
public:
    int longestSubstring(string s, int k) {
        int n = s.length();
		if(n < k){
			return 0;
		}
		// create and init
		int *count = new int[26];
		int ans = 0;
		memset(count, 0, sizeof(int) * 26);
		// count
		for(int i = 0; i <= n - 1; i++){
			count[s[i] - 'a']++;
		}
		// find the first character that its frequency < k
		int start = 0, i = 0;
		while(i <= n - 1){
			if(count[s[i] - 'a'] < k){
				ans = max(ans, longestSubstring(s.substr(start, i - start), k));
				start = i + 1;
				i = start;
			}
			else{
				i++;
			}
		}
		// get answer
		if(start == 0){
			return n;
		}
		else if(start >= 1 && start <= n - 1){
			ans = max(ans, longestSubstring(s.substr(start, n), k));
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	int k;
	while(cin >> s >> k){
		cout << "ans: " << sol.longestSubstring(s, k) << endl;
	}
	return 0;
}
