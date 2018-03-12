#include <bits/stdc++.h>
using namespace std;

// map
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
		int n1 = ransomNote.length(), n2 = magazine.length();
		// Exceptional Case: 
		if(n1 > n2){
			return false;
		}
		if(!n1){
			return true;
		}
        map<char, int> m1, m2;
		for(char c1: ransomNote){
			m1[c1]++;
		}
		for(char c2: magazine){
			m2[c2]++;
		}
		for(auto &p: m1){
			if(m2.count(p.first) && m2[p.first] >= m1[p.first]){
				continue;
			}
			return false;
		}
		return true;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string ransomNote, magazine;
	while(cin >> ransomNote >> magazine){
		cout << "ans: " << sol.canConstruct(ransomNote, magazine) << endl;
	}
	return 0;
}
