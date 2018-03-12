#include <bits/stdc++.h>

using namespace std;

#define LL long long

// math
class Solution {
public:
    int findNthDigit(int n) {
        LL start = 1, bit = 1, base = 9, cnt = 9;
		while((LL)n > cnt){
			bit += 1;
			base *= 10;
			start *= 10;
			cnt += (bit * base);
		}
		cnt -= bit * base;
		int N = n - (int)cnt;
		int D = N / (int)bit, R = N % (int)bit;
		int num = (int)start + D - 1;
		if(R == 0){
			return num % 10;
		}
		num += 1;
		for(int i = 1; i <= (int)bit - R; i++){
			num /= 10;
		}
		return num % 10;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.findNthDigit(n) << endl;
	}
	return 0;
}
