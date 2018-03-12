#include <bits/stdc++.h>
using namespace std;


/*
	1. L(n) + R(n) = n + 1 => L(n / 2) + R(n / 2) = n / 2 + 1
	2. L(n) = 2 * R(n / 2)
	=> L(n) = 2 * (n / 2 + 1 - L(n / 2))
*/
/*
// DFS
// Accepted
class Solution {
public:
    int lastRemaining(int n) {
		if(n <= 0){
			return 0;
		}
        if(n == 1){
			return 1;
		}
		return 2 * (n / 2 + 1 - lastRemaining(n / 2));
    }
};
*/

// update the start and the step
class Solution {
public:
    int lastRemaining(int n) {
		if(n <= 0){
			return 0;
		}
		int start = 1, step = 1;
		int cnt = n;
		bool left = true;
		while(cnt > 1){
			if(left || (cnt & 1)){
				start += step;
			}
			cnt /= 2;
			step *= 2;
			left = !left;
		}
		return start;
	}
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.lastRemaining(n) << endl;
	}
	return 0;
}
