#include<bits/stdc++.h>

using namespace std;

// binary search
class Solution {
public:
    int arrangeCoins(int n) {
		int left = 1, right = 65535;
		while(left <= right){
			int mid = left + ((right - left) >> 1);
			// check whether mid is a even or odd
			int sum = (mid & 1)? (mid + 1) / 2 * mid: mid / 2 * (mid + 1);
			if(sum <= n){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return right;
    }
};

int main(int argc, char** argv){
	double N = 2147483647.0;
	cout << "sqrt: " << sqrt(2 * N) << endl;
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.arrangeCoins(n) << endl;
	}
	return 0;
}
