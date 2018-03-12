#include<bits/stdc++.h>

using namespace std;

// bit manipulation
class Solution {
public:
    int hammingDistance(int x, int y) {
        int ans = 0;
		for(int i = 31; i >= 0; i--){
			int bit = ((x >> i) & 1) ^ ((y >> i) & 1);
			ans += bit;
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int x, y;
	while(cin >> x >> y){
		cout << "ans: " << sol.hammingDistance(x, y) << endl;
	}
	return 0;
}
