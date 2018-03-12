#include <bits/stdc++.h>

using namespace std;

#define LL long long

/*
	1. n = 2 * k => then n = n / 2 = k; 
	2. n = 2 * k + 1 => n + 1 = 2 * (k + 1), (n + 1) / 2 = k + 1, 
					 => n - 1 = 2 * k, (n - 1) / 2 = k, 
		i. if k + 1 = 2 * t, we choose n + 1 ((n + 1) % 4 == 0)
		ii. if k = 2 * t, we choose n - 1 ((n - 1) % 4 == 0)
*/
// math + bit manipulation
class Solution {
public:
    int integerReplacement(int n) {
        if(n <= 1){
			return n - 1;
		}
		LL N = n;
		int ans = 0;
		while(N > 1){
			// even
			if(!(N & 1)){
				N >>= 1;
			}
			// odd
			else{
				if((N + 1) % 4 == 0 && N != 3){
					N += 1;
				}
				else{
					N -= 1;
				}
			}
			ans++;
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.integerReplacement(n) << endl;
	}
	return 0;
}
