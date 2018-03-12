#include<bits/stdc++.h>
using namespace std;

// bit manipulation
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && n == (-n & n);
    }
};

int main(){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.isPowerOfTwo(n) << endl;
	}
	return 0;
}
