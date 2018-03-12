#include<bits/stdc++.h>

using namespace std;

// set + map
class Solution {
private: 
	// set compare struct
	struct cmp{
		bool operator()(const pair<char, int> &p1, const pair<char, int> &p2)const{
			if(p1.second != p2.second){
				return p1.second > p2.second;
			}
			return p1.first < p2.first;
		}
	};

public:
    string frequencySort(string s) {
		if(s.length() <= 1){
			return s;
		}
		set<pair<char, int>, cmp> se;
		map<char, int> m;
		for(char c: s){
			if(m.count(c)){
				auto its = se.find(make_pair(c, m[c]));
				se.erase(its);
			}
			m[c]++;
			se.insert(make_pair(c, m[c]));
		}
		// get answer
		string ans = "";
		for(auto p: se){
			ans += string(p.second, p.first);
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.frequencySort(s) << endl;
	}
	return 0;
}
