#include<bits/stdc++.h>

using namespace std;

// bit manipulation
class Solution {
private: 
	string str[16] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};

public:
    string toHex(int num) {
		if(!num){
			return "0";
		}
		string ans = "";
		int cnt = 0;
		while(num){
			// get the last four bits
			ans.insert(0, str[num & 15]);
			if(++cnt == 8){
				break;
			}
			// remove the last four bits
			num >>= 4;
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.toHex(n) << endl;
	}
	return 0;
}
