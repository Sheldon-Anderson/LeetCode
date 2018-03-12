#include <bits/stdc++.h>
using namespace std;

// math
class Solution {
public:
    int addDigits(int num) {
        if(num == 0){
			return 0;
		}
		int r = num % 9;
		return r == 0? 9: r;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans:" << sol.addDigits(num) << endl;
	}
	return 0;
}
