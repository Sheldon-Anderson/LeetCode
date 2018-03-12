#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length(), n2 = t.length();
		if(!n1 && !n2){
			return true;
		}
		if(n1 != n2){
			return false;
		}
		map<char, char> m1, m2;
		for(int i = 0; i <= n1 - 1; i++){
			if(m1.count(s[i]) && m2.count(t[i])){
				if(m1[s[i]] == t[i] && m2[t[i]] == s[i]){
					continue;
				}
				else{
					return false;
				}
			}
			else if(m1.count(s[i]) || m2.count(t[i])){
				return false;
			}
			else{
				m1[s[i]] = t[i];
				m2[t[i]] = s[i];
			}
		}
		return true;
    }
};

int main(){
	Solution sol;
	string s, t;
	while(cin >> s >> t){
		cout << "ans: " << sol.isIsomorphic(s, t) << endl;
	}
	return 0;
}
