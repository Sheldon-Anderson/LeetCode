#include<bits/stdc++.h>
using namespace std;

#define LL long long

class Solution {
public:
    bool isPalindrome(int x) {
		// Exceptional Case: 
		if(x < 0){
			return false;
		}
		if(x == 0){
			return true;
		}
		int t = x;
        LL y = 0;
		while(t){
			y = y * 10 + (t % 10);
			t /= 10;
		}
		return y == (LL)x;
    }
};

int main(){
	Solution sol;
	int x;
	while(cin >> x){
		cout << "ans: " << sol.isPalindrome(x) << endl;
	}
	return 0;
}
