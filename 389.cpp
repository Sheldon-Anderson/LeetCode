#include <bits/stdc++.h>
using namespace std;

/*
// count
// Accepted
class Solution {
public:
    char findTheDifference(string s, string t) {
        // create and init
		int *count = new int[26];
		memset(count, 0, sizeof(int) * 26);
		// count
		for(char c2: t){
			count[c2 - 'a']++;
		}
		for(char c1: s){
			count[c1 - 'a']--;
		}
		// get answer
		int pos = -1;
		for(int i = 0; i <= 25; i++){
			if(count[i]){
				pos = i;
				break;
			}
		}
		return pos + 'a';
    }
};
*/

// bit manipulation
class Solution {
public:
    char findTheDifference(string s, string t) {
		int ans = 0;
		for(char c1: s){
			ans ^= (c1 - 'a');
		}
		for(char c2: t){
			ans ^= (c2 - 'a');
		}
		return ans + 'a';
	}
};

int main(int argc, char** argv){
	Solution sol;
	string s, t;
	while(cin >> s >> t){
		cout << "ans: " << sol.findTheDifference(s, t) << endl;
	}
	return 0;
}
