#include <bits/stdc++.h>

using namespace std;

/*
// bit manipulation
// Accepted
class Solution {
public:
    int getSum(int a, int b) {
        while(b){
			int x = a ^ b;
			int y = (a & b) << 1;
			a = x;
			b = y;
		}
		return a;
    }
};
*/

// bit manipulation
class Solution {
private: 
	int DFS(int a, int b){
		if(!b){
			return a;
		}
		return DFS(a ^ b, (a & b) << 1);
	}

public:
    int getSum(int a, int b) {
		return DFS(a, b);
	}
	
	int getNegative(int a){
		return getSum(~a, 1);
	}
	
	int getSub(int a, int b){
		return getSum(a, getNegative(b));
	}
	
	int getPositiveMul(int a, int b){
		int ans = 0;
		while(b){
			if(b & 1){
				ans = getSum(ans, a);
			}
			a <<= 1;
			b >>= 1;
		}
		return ans;
	}
	
	int getPositiveDiv(int a, int b){
		int ans = 0;
		for(int i = 31; i >= 0; i--){
			if((a >> i) >= b){
				// D = 1 << i, R = getSub(a, (b << i));
				ans = getSum(ans, (1 << i));
				a = getSub(a, (b << i));
			}
		}
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	int a, b;
	while(cin >> a >> b){
		cout << "sum: " << sol.getSum(a, b) << endl;
		cout << "negative: " << sol.getNegative(a) << endl;
		cout << "sub: " << sol.getSub(a, b) << endl;
		cout << "mul: " << sol.getPositiveMul(a, b) << endl;
		cout << "div: " << sol.getPositiveDiv(a, b) << endl;
	}
	return 0;
}
