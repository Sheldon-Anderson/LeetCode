#include <bits/stdc++.h>

using namespace std;

#define LL long long
// for case: a = 2147483647, b = {2, 0, 0}

// math problem: calculate: a^b mod 1337
// Euler's totient function and Euler's theorem + fast exponentiation
class Solution {
public:
    int superPow(int a, vector<int>& b) {
        if(a == 0){
			return 0;
		}
		int n = b.size();
		if(n == 0){
			return 1;
		}
		int mod = 1337;
		// 1. Euler's totient function and Euler's theorem
		// 1337 = 7 * 191, φ(1337) = φ(7) * φ(191) = 6 * 190 = 1140
		int Euler = 1140;
		// get exp
		int exp = 0;
		for(int i = 0; i <= n - 1; i++){
			exp = (exp * 10 + b[i]) % Euler;
		}
		// 2. fast exponentiation
		LL base = (LL)a;
		LL ans = 1;
		while(exp > 0){
			if(exp & 1){
				ans = (ans * base) % mod;
			}
			base = (base * base) % mod;
			exp >>= 1;
		}
		// get answer
		return (int)ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int a = 2;
	vector<int> b = {1, 0};
	cout << "ans: " << sol.superPow(a, b) << endl;
	return 0;
}
