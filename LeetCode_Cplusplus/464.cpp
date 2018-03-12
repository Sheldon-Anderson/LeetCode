#include<bits/stdc++.h>

using namespace std;

// DFS + memory + bit manipulation
class Solution {
private: 
	map<int, bool> m;

	// mark saves the status (used or unused) for numbers from 1 to maxChoosableInteger
	bool DFS(int maxVal, int target, int mark){
		if(m.count(mark)){
			return m[mark];
		}
		for(int i = 1; i <= maxVal; i++){
			if(!((1 << i) & mark)){
				if(target <= i || !DFS(maxVal, target - i, (1 << i) | mark)){
					m[mark] = true;
					return true;
				}
			}
		}
		m[mark] = false;
		return false;
	}

public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
		// Exceptional Case: 
        if(maxChoosableInteger >= desiredTotal){
			return true;
		}
		if(maxChoosableInteger * (maxChoosableInteger + 1) / 2 < desiredTotal){
			return false;
		}
		// get answer
		return DFS(maxChoosableInteger, desiredTotal, 0);
    }
};

int main(int argc, char** argv){
	Solution sol;
	int maxChoosableInteger, desiredTotal;
	while(cin >> maxChoosableInteger >> desiredTotal){
		cout << "ans: " << sol.canIWin(maxChoosableInteger, desiredTotal) << endl;
	}
	return 0;
}
