#include <bits/stdc++.h>
using namespace std;

// map
class Solution {
public:
    bool isAnagram(string s, string t) {
        int n1 = s.length(), n2 = t.length();
		if(n1 == 0 && n2 == 0){
			return true;
		}
		else if(n1 != n2){
			return false;
		}
		map<char, int> m;
		for(int i = 0; i <= n1 - 1; i++){
			m[s[i]]++;
		}
		for(int i = 0; i <= n2 - 1; i++){
			if(m.count(t[i])){
				if(!--m[t[i]]){
					m.erase(t[i]);
				}
			}
			else{
				return false;
			}
		}
		return !m.size();
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s, t;
	while(cin >> s >> t){
		cout << "ans: " << sol.isAnagram(s, t) << endl;
	}
	return 0;
}
