#include <bits/stdc++.h>
using namespace std;

// map
class Solution {
private: 
// check if string s is a palindrome
	bool check(string s){
		int L = s.length();
		for(int i = 0; i <= L / 2 - 1; i++){
			if(s[i] != s[L - 1 - i]){
				return false;
			}
		}
		return true;
	}

public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n = words.size();
		if(n <= 1){
			return vector<vector<int>>();
		}
		vector<vector<int>> ans;
		map<string, int> m;
		// map
		for(int i = 0; i <= n - 1; i++){
			m[words[i]] = i;
		}
		// judge 1: "abba", ""
		for(int i = 0; i <= n - 1; i++){
			if(words[i] != "" && check(words[i]) && m.count("")){
				ans.push_back(vector<int>{i, m[""]});
				ans.push_back(vector<int>{m[""], i});
			}
		}
		// judge 2: "abcd", "dcba"
		for(int i = 0; i <= n - 1; i++){
			if(words[i] != ""){
				string rstr(words[i].rbegin(), words[i].rend());
				if(m.count(rstr) && m[rstr] != i){
					ans.push_back(vector<int>{i, m[rstr]});
				}
			}
		}
		// judge 3: "(aba)dc", "cd"
		for(int i = 0; i <= n - 1; i++){
			if(words[i] != ""){
				int L = words[i].length();
				for(int j = 1; j <= L - 1; j++){
					string Lstr = words[i].substr(0, j);
					string Rstr = words[i].substr(j, L - j);
					string rLstr(Lstr.rbegin(), Lstr.rend());
					string rRstr(Rstr.rbegin(), Rstr.rend());
					// (ss)sll, lls
					if(check(Lstr) && m.count(rRstr)){
						ans.push_back(vector<int>{m[rRstr], i});
					}
					// sll(ss), lls
					if(check(Rstr) && m.count(rLstr)){
						ans.push_back(vector<int>{i, m[rLstr]});
					}
				}
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<string> words = {"a", "abc", "aba", ""};	// {"bat", "tab", "cat"};	// {"abcd", "dcba", "lls", "s", "sssll"};
	vector<vector<int>> ans = sol.palindromePairs(words);
	// console output
	for(auto p: ans){
		cout << p[0] << ", " << p[1] << endl;
	}
	return 0;
}
