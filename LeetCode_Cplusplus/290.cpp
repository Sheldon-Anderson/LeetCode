#include <bits/stdc++.h>
using namespace std;

// map
class Solution {
public:
    bool wordPattern(string pattern, string str) {
        int n1 = pattern.length(), n2 = str.length();
		if(n1 == 0 || n2 == 0){
			return false;
		}
		vector<string> vec;
		istringstream iss(str);
		string s;
		while(getline(iss, s, ' ')){
			vec.push_back(s);
		}
		if(n1 != vec.size()){
			return false;
		}
		map<char, string> m1;
		map<string, char> m2;
		for(int i = 0; i <= n1 - 1; i++){
			if(!m1.count(pattern[i]) && !m2.count(vec[i])){
				m1[pattern[i]] = vec[i];
				m2[vec[i]] = pattern[i];
			}
			else if(m1.count(pattern[i]) && m2.count(vec[i]) && m1[pattern[i]] == vec[i] && m2[vec[i]] == pattern[i]){
				continue;
			}
			else{
				return false;
			}
		}
		return true;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string pattern, str;
	while(cin >> pattern){
		cin.get();
		getline(cin, str);
		// test
		cout << "pattern: " << pattern << ", str: " << str << endl;
		cout << "ans: " << sol.wordPattern(pattern, str) << endl;
	}
	return 0;
}
