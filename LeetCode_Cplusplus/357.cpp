#include <bits/stdc++.h>
using namespace std;

// math + dynamic programming
// f(k) = 9 * 9 * 8 * ... * (11 - k)
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n == 0){
			return 1;
		}
		if(n == 1){
			return 10;
		}
		int ans = 10, base = 9;
		for(int i = 2; i <= min(n, 10); i++){
			base *= (11 - i);
			ans += base;
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.countNumbersWithUniqueDigits(n) << endl;
	}
	return 0;
}
