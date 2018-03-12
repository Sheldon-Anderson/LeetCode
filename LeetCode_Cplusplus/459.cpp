#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
		int n = s.length();
        if(!n){
			return false;
		}
		for(int i = 1; i <= n / 2; i++){
			string str = s.substr(0, i);
			int start = i;
			while(start <= n - 1 && s.substr(start, i) == str){
				start += i;
			}
			if(start == n){
				return true;
			}
		}
		return false;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.repeatedSubstringPattern(s) << endl;
	}
	return 0;
}
