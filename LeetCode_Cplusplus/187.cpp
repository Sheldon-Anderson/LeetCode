#include<bits/stdc++.h>
using namespace std;

// map
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ans;
		int n = s.length();
		if(n <= 9){
			return ans;
		}
		map<string, int> m;
		for(int i = 0; i <= n - 10; i++){
			m[s.substr(i, 10)]++;
		}
		// get answer
		for(auto &p: m){
			if(p.second >= 2){
				ans.push_back(p.first);
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	string s;
	while(cin >> s){
		vector<string> ans = sol.findRepeatedDnaSequences(s);
		// console output
		for(string str: ans){
			cout << str << " ";
		}
		cout << endl;
	}
	return 0;
}
