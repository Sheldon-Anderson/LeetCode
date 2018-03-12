#include<bits/stdc++.h>
using namespace std;

#define LL long long

class Solution {
public:
    int trailingZeroes(int n) {
		if(n <= 0){
			return 0;
		}
        LL base = 5;
		int ans = 0;
		while(n >= base){
			ans += (n / base);
			base *= 5;
		}
		return ans;
    }
};

int main(){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.trailingZeroes(n) << endl;
	}
	return 0;
}
