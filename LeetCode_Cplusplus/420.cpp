#include<bits/stdc++.h>

using namespace std;

/*
	(1). s.length() < 6
	(2). 6 <= s.length() <= 20
		=>(1)(2): greedy algorithm: 
		for (1), insertion for >= 3-char repetitions
		for (2), replacement for >= 3-char repetitions
	(3). s.length() > 20
		=> we suppose len: the length of each repetition,
		   we use deletions to reduce replacements: 
		   i. len % 3 == 0: 1 deletion
		   ii. len % 3 == 1: 2 deletions
		   iii. len % 3 == 2: 3 deletions
*/
class Solution {
public:
    int strongPasswordChecker(string s) {
        int n = s.length();
		bool upper = true, lower = true, digit = true;
		int toInsert = max(0, 6 - n), toDelete = max(0, n - 20);
		int hasInsert = 0, hasDelete = 0, hasReplace = 0;
		// save the length of each repetition and value of length % 3
		vector<vector<int>> repeats(3);
		for(int j = 0, i = 0; i <= n; i++){
			if(i == n || s[j] != s[i]){
				if(i - j >= 3){
					repeats[(i - j) % 3].push_back(i - j);
				}
				j = i;
			}
			if(i <= n - 1){
				if(isupper(s[i])){
					upper = false;
				}				
				if(islower(s[i])){
					lower = false;
				}				
				if(isdigit(s[i])){
					digit = false;
				}
			}
		}
		// count the insertions, deletions and replacements
		for(int i = 0; i <= 2; i++){
			if(!repeats[i].size()){
				continue;
			}
			for(int j = 0; j <= repeats[i].size() - 1; j++){
				if(i <= 1){
					/*
						for example: 
						1. aaaa: 4 % 3 == 1 => aaBaa, 4 - 2 = 2
						2. aaa: 3 % 3 == 0 => aaBa, 3 - 2 = 1
					*/
					if(toInsert - hasInsert){
						hasInsert++;
						repeats[i][j] -= (i + 1);
					}
					else if(toDelete - hasDelete){
						hasDelete += (i + 1);
						repeats[i][j] -= (i + 1);
					}
				}
				hasReplace += repeats[i][j] / 3;
			}
		}
		// deal with toDelete and hasDelete
		if(toDelete > hasDelete){
			hasReplace = max(0, hasReplace - (toDelete - hasDelete) / 3);
		}
		else{
			hasReplace += (hasDelete - toDelete);
		}
		// get answer
		return toDelete + max(toInsert + hasReplace, upper + lower + digit);
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(cin >> s){
		cout << "ans: " << sol.strongPasswordChecker(s) << endl;
	}
	return 0;
}
