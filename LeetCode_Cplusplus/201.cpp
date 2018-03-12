 #include<bits/stdc++.h>
using namespace std;

#define LL long long

// bit manipulation
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
		int bits_m = floor((log(m)) / (log(2))), bits_n = floor((log(n)) / (log(2)));
		// Exceptional Case: 
		if(m == 0 || bits_m != bits_n){
			return 0;
		}
		bool f1 = false;
		int ans = 0;
		for(int i = bits_m; i >= 0; i--){
			bool f2 = false;
			// for case: m = 2147483646, n = 2147483647
			for(LL j = (LL)m; j <= (LL)n; j++){
				if(j == (1 << i)){
					f1 = true;
				}
				if(!((j >> i) & 1)){
					f2 = true;
					break;
				}
			}
			if(!f2){
				ans += (1 << i);
			}
			if(f1){
				break;
			}
		}
        return ans;
    }
};

int main(){
	Solution sol;
	int m, n;
	while(cin >> m >> n){
		cout << "ans: " << sol.rangeBitwiseAnd(m, n) << endl;
	}
	return 0;
}
