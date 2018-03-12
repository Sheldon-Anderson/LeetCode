#include<bits/stdc++.h>
using namespace std;

// bit manipulation
class Solution {
public:
    int hammingWeight(uint32_t n) {
		int ans = 0;
        for(int i = 31; i >= 0; i--){
			if((n >> i) & 1){
				ans++;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	uint32_t n;
	while(cin >> n){
		cout << "ans: " << sol.hammingWeight(n) << endl;
	}
	return 0;
}
