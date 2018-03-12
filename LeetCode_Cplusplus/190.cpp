#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
		for(int i = 31; i >= 0; i--){
			if((n >> i) & 1){
				ans += (1 << (31 - i));
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	uint32_t n;
	while(cin >> n){
		cout << "ans: " << sol.reverseBits(n) << endl;
	}
	return 0;
}
