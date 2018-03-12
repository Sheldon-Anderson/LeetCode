#include<bits/stdc++.h>
using namespace std;

#define LL long long

/*
   start:					end: 
   A: 1			 	 		Z: 26
   AA: 26 + 1				ZZ: (26 + 1) * 26 = 26 * 26 + 26
   AAA: 26 * 26 + 26 + 1	ZZZ: (26 * 26 + 26 + 1) * 26 = 26 * 26 * 26 + 26 * 26 + 26
*/
class Solution {
public:
    string convertToTitle(int n) {
		string ans = "";
		if(n <= 0){
			return "";
		}
		if(n >= 1 && n <= 26){
			ans += ('A' + n - 1);
			return ans;
		}
		LL nn = n;
		LL base = 26;
		LL exp, r;
		while(true){
			if(nn > base){
				r = nn % base;
				if(!r){
					ans += 'Z';
					nn -= base;
				}
				else{
					exp = r / (base / 26);
					ans += ('A' + exp - 1);
					nn -= r;
				}
				base *= 26;
			}
			else if(nn <= base){
				exp = nn / (base / 26);
				ans += ('A' + exp - 1);
				break;
			}
		}
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

int main(){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.convertToTitle(n) << endl;
	}
	return 0;
}
