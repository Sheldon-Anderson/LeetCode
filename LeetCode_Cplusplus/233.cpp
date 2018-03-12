#include<bits/stdc++.h>
using namespace std;

#define LL long long

/* 
	math formula: 
		for n and base: 
		d = n / base, 
		r = n % base, 
		count = ((d + 8) / 10 * base + (d % 10 == 1) * (r + 1))

*/
class Solution {
public:
    int countDigitOne(int n) {
        if(n <= 0){
			return 0;
		}
		// for case: n = 1410065408
		LL base = 1;
		int ans = 0;
		while(base <= n){
			int d = n / base;
			int r = n % base;
		    // debug
		    // cout << "base: " << base << ", d: " << d << ", r: " << r << endl;
			ans += ((d + 8) / 10 * base + (d % 10 == 1) * (r + 1));
			base *= 10;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.countDigitOne(n) << endl;
	}
	return 0;
}
