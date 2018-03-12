#include<bits/stdc++.h>
using namespace std;

// math
class Solution {
public:
    bool isUgly(int num) {
        if(num <= 0){
			return false;
		}
		while(!(num % 2)){
			num /= 2;
		}
		while(!(num % 3)){
			num /= 3;
		}
		while(!(num % 5)){
			num /= 5;
		}
		return num == 1;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans: " << sol.isUgly(num) << endl;
	}
	return 0;
}
