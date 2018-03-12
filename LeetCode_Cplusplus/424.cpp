#include<bits/stdc++.h>

using namespace std;

// sliding window algorithm
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
		if(!n){
			return 0;
		}
		// create and init
		int *count = new int[26];
		memset(count, 0, sizeof(int) * 26);
		// slide
		int left = 0, right = 0, maxCount = 0, ans = 0;
		while(left <= right && right <= n - 1){
			maxCount = max(maxCount, ++count[s[right] - 'A']);
			while(right - left + 1 - maxCount > k){
				count[s[left++] - 'A']--;
				// update maxCount
				for(int i = 0; i <= 25; i++){
					maxCount = max(maxCount, count[i]);
				}
			}
			// update answer
			ans = max(ans, right++ - left + 1);
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	int k;
	while(cin >> s >> k){
		cout << "ans: " << sol.characterReplacement(s, k) << endl;
	}
	return 0;
}
