#include<bits/stdc++.h>

using namespace std;

// map + sliding window
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n1 = s.length(), n2 = p.length();
		if(n1 < n2){
			return vector<int>();
		}
		vector<int> ans;
		// count string p
		map<char, int> ms, mp;
		for(char c: p){
			mp[c]++;
		}
		int left = 0, right = 0;
		while(left <= right && right <= n1 - 1){
			if(!mp.count(s[right])){
				left = right + 1;
				right = left;
				ms.clear();
			}
			else{
				ms[s[right]]++;
				if(right - left + 1 == n2){				
					if(ms == mp){
						ans.push_back(left);
					}
					if(ms[s[left]] == 1){
						ms.erase(s[left]);
					}
					else{
						ms[s[left]]--;
					}
					left++;
				}
				right++;
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s, p;
	while(cin >> s >> p){
		vector<int> ans = sol.findAnagrams(s, p);
		// console output
		for(int val: ans){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
