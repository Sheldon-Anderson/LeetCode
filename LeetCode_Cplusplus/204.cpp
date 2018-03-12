#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2){
			return 0;
		}
		// create
		bool *prime = new bool[n];
		memset(prime, true, sizeof(bool) * (n));
		prime[0] = prime[1] = false;
		prime[2] = true;
		int ans = 0;
		for(int i = 2; i <= n - 1; i++){
			if(prime[i]){
				ans++;
				for(int j = i + i; j <= n - 1; j += i){
					prime[j] = false;
				}
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.countPrimes(n) << endl;
	}
	return 0;
}
