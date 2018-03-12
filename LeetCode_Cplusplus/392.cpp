#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n1 = s.length(), n2 = t.length();
		if(n1 > n2){
			return false;
		}
		int i = 0, j = 0;
		while(i <= n1 - 1){
			while(j <= n2 - 1 && t[j] != s[i]){
				j++;
			}
			if(j == n2){
				return false;
			}
			i++;
			j++;
		}
		return true;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s, t;
	while(cin >> s >> t){
		cout << "ans: " << sol.isSubsequence(s, t) << endl;
	}
	return 0;
}
