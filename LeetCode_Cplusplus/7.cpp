#include<bits/stdc++.h>
using namespace std;

#define LL long long

class Solution {
public:
    int reverse(int x) {
		// Exceptional Case: 
		if(x == 0){
			return 0;
		}
		LL xx = (LL)x, yy = 0;
		int sign = 1;
		if(xx < 0){
			sign = -1;
			xx = -xx;
		}
		while(xx){
			yy = yy * 10 + (xx % 10);
			xx /= 10;
		}
		if(sign == -1){
			yy = -yy;
		}
		if((sign == 1 && yy <= INT_MAX) ||  (sign == -1 && yy >= INT_MIN)){
			return (int)yy;
		}
        return 0;
    }
};

int main(){
	Solution sol;
	int x;
	while(cin >> x){
		cout << "ans: " << sol.reverse(x) << endl;
	}
	return 0;
}
