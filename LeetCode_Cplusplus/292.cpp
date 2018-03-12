#include <bits/stdc++.h>
using namespace std;

// math
class Solution {
public:
    bool canWinNim(int n) {
        return n % 4;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.canWinNim(n) << endl;
	}
	return 0;
}
