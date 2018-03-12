#include<bits/stdc++.h>

using namespace std;

// bit manipulation
class Solution {
public:
    int findComplement(int num) {
		int pos = -1;
        for(int i = 31; i >= 0; i--){
			if((1 << i) & num){
				pos = i;
				break;
			}
		}
		// get answer
		int ans = 0;
		for(int i = pos; i >= 0; i--){
			ans += ((1 << i) & num)? 0: (1 << i);
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans: " << sol.findComplement(num) << endl;
	}
	return 0;
}
