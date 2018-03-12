#include <bits/stdc++.h>

using namespace std;

// bit manipulation
class Solution {
private: 
	// check one byte
	int check(int digit){
		// 11110xxx
		if(((digit >> 3) & 1) == 0 && (digit >> 4) == 15){
			return 4;
		}
		// 1110xxxx
		else if(((digit >> 4) & 1) == 0 && (digit >> 5) == 7){
			return 3;
		}
		// 110xxxxx
		else if(((digit >> 5) & 1) == 0 && (digit >> 6) == 3){
			return 2;
		}
		// 10xxxxxx
		else if(((digit >> 6) & 1) == 0 && (digit >> 7) == 1){
			return 1;
		}
		// 0xxxxxxx
		else if(((digit >> 7) & 1) == 0){
			return 0;
		}
		// other cases
		return -1;
	}

public:
    bool validUtf8(vector<int>& data) {
		int n = data.size();
		if(!n){
			return true;
		}
		int i = 0;
		while(i <= n - 1){
			// 11110xxx
			if(check(data[i]) == 4){
				if(i + 3 <= n - 1 && check(data[i + 1]) == 1 && check(data[i + 2]) == 1 && check(data[i + 3]) == 1){
					i += 4;
				}
				else{
					return false;
				}
			}
			// 1110xxxx
			else if(check(data[i]) == 3){
				if(i + 2 <= n - 1 && check(data[i + 1]) == 1 && check(data[i + 2]) == 1){
					i += 3;
				}
				else{
					return false;
				}
			}
			// 110xxxxx
			else if(check(data[i]) == 2){
				if(i + 1 <= n - 1 && check(data[i + 1]) == 1){
					i += 2;
				}
				else{
					return false;
				}
			}
			// 0xxxxxxx
			else if(check(data[i]) == 0){
				i += 1;
			}
			else{
				return false;
			}
		}
		return true;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> data = {206,210,189,208,197,163,182,171,212,243,10,0,10};
	cout << "ans: " << sol.validUtf8(data);
	return 0;
}
