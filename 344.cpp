#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseString(string s) {
        int n = s.length();
		if(n <= 1){
			return s;
		}
		for(int i = 0; i <= n / 2 - 1; i++){
			swap(s[i], s[n - 1 - i]);
		}
		return s;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(getline(cin, s)){
		cout << "ans: " << sol.reverseString(s) << endl;
	}
	return 0;
}
