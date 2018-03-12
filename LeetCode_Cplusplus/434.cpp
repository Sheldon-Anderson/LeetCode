#include<bits/stdc++.h>

using namespace std;

// istringstream, getline
class Solution {
public:
    int countSegments(string s) {
        int n = s.length();
		if(!n){
			return 0;
		}
		istringstream iss(s);
		string str;
		int ans = 0;
		while(getline(iss, str, ' ')){
			if(str != ""){
				ans++;
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(getline(cin, s)){
		cout << sol.countSegments(s) << endl;
	}
	return 0;
}
