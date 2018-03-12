#include <bits/stdc++.h>
using namespace std;

// bit manipulation
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
		if(n == 0){
			return 0;
		}
		// create and init
		int *mask = new int[n];
		memset(mask, 0, sizeof(int) * n);
		// mask code
		for(int i = 0; i <= n - 1; i++){
			for(int j = 0; j < words[i].length(); j++){
				mask[i] |= (1 << (words[i][j] - 'a'));
			}
		}
		// find the maximum product
		int ans = 0;
		for(int i = 0; i <= n - 2; i++){
			for(int j = i + 1; j <= n - 1; j++){
				if(!(mask[i] & mask[j])){
					ans = max(ans, (int)words[i].length() * (int)words[j].length());
				}
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<string> words = {"a", "aa", "aaa", "aaaa"};	// {"a", "ab", "abc", "d", "cd", "bcd", "abcd"};	// {"abcw", "baz", "foo", "bar", "xtfn", "abcdef"};
	cout << "ans: " << sol.maxProduct(words) << endl;
	return 0;
}
