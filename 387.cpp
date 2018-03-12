#include <bits/stdc++.h>
using namespace std;

// map
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
		if(!n){
			return -1;
		}
		map<char, int> m;
		for(int i = 0; i <= n - 1; i++){
			m[s[i]]++;
		}
		for(int i = 0; i <= n - 1; i++){
			if(m[s[i]] == 1){
				return i;
			}
		}
		return -1;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.firstUniqChar(s) << endl;
	}
	return 0;
}
