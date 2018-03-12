#include <bits/stdc++.h>
using namespace std;

#define LL long long

// DFS
class Solution {
private: 
	bool add, ans;
	stringstream stream;
	
	void DFS(string num, int n, int pos, LL d1, LL d2){
		// debug
		// cout << "pos: " << pos << ", d1: " << d1 << ", d2: " << d2 << endl;
		if((pos == n && add) || ans){
			ans = true;
			return;
		}
		for(int i = 1; i <= n - pos; i++){
			string str = num.substr(pos, i);
			// leading zeros
			if(str[0] == '0' && i > 1){
				continue;
			}
			LL digit;
			stream << str;
			stream >> digit;
			stream.clear();
			if(d1 == -1){
				// d1 = digit;
				DFS(num, n, pos + i, digit, d2);
			}
			else if(d2 == -1){
				// d2 = digit;
				DFS(num, n, pos + i, d1, digit);
			}
			else if(d1 + d2 == digit){
				// d1 = d2;
				// d2 = digit;
				add = true;
				DFS(num, n, pos + i, d2, digit);
				add = false;
			}
		}
	}

public:
    bool isAdditiveNumber(string num) {
		int n = num.length();
		if(n <= 1){
			return false;
		}
		ans = false;
		add = false;
        DFS(num, n, 0, -1, -1);
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string num;
	while(cin >> num){
		cout << "ans: " << sol.isAdditiveNumber(num) << endl;
	}
	return 0;
}
