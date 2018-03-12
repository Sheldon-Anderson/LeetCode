#include <bits/stdc++.h>

using namespace std;

#define eps 1e-8

/*
// Accepted
#define eps 1e-8

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0){
            return false;
        }
        int exp = (ceil)(log(n) / log(3));
		return fabs(pow(3, exp) - n) <= eps;
    }
};
*/

/*
// Accepted
class Solution {
public:
    bool isPowerOfThree(int n) {
		if(n <= 0){
			return false;
		}
		// N is the max integer that is power of three
		int N = (int)pow(3, 19);
		return N % n == 0;
	}
};
*/

class Solution {
public:
    bool isPowerOfThree(int n) {
		if(n <= 0){
			return false;
		}
		while(!(n % 3)){
			n /= 3;
		}
		return n == 1;
	}
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.isPowerOfThree(n) << endl;
	}
	return 0;
}
