#include <bits/stdc++.h>
using namespace std;

#define eps 1e-8

/*
// math
// Accepted
class Solution {
public:
    bool isPowerOfFour(int num) {
        if(num <= 0){
			return false;
		}
		int exp = (ceil)(log(num) / log(4));
		if(fabs(pow(4, exp) - num) <= eps){
			return true;
		}
		return false;
    }
};
*/

// bit manipulation
class Solution {
public:
    bool isPowerOfFour(int num) {
		return (num >= 1) && (num == (num & (-num))) && ((num - 1) % 3 == 0);
	}
};

int main(){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans: " << sol.isPowerOfFour(num) << endl;
	}
	return 0;
}
