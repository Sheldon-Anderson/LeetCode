#include<bits/stdc++.h>

using namespace std;

#define LL long long

/*
	n1 = curr, n2 = cur + 1, n, k
	=> 1. n2 <= n: step += (n2 - n1)
	=> 2. n2 > n: step += (n + 1 - n1)
	=> step += min(n2, n + 1) - n1
*/
// denary tree
class Solution {
private: 
	int getSteps(LL n1, LL n2, int n){
		int res = 0;
		while(n1 <= (LL)n){
			res += min((int)n2, n + 1) - (int)n1;
			n1 *= 10;
			n2 *= 10;
		}
		return res;
	}

public:
    int findKthNumber(int n, int k) {
		// the kth means move (k - 1) steps from 1
        k -= 1;
		// for case: n = 681692778, k = 351251360
		LL cur = 1;
		while(k){
			int steps = getSteps(cur, cur + 1, n);
			if(steps <= k){
				cur += 1;
				k -= steps;
			}
			else{
				cur *= 10;
				k -= 1;
			}
		}
		// get answer
		return cur;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n, k;
	while(cin >> n >> k){
		cout << "ans: " << sol.findKthNumber(n, k) << endl;
	}
	return 0;
}
