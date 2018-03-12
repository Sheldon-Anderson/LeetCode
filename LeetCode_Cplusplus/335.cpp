#include <bits/stdc++.h>
using namespace std;

// math
class Solution {
public:
    bool isSelfCrossing(vector<int>& x) {
        int n = x.size();
		if(n <= 3){
			return false;
		}
		for(int i = 3; i <= n - 1; i++){
			// i >= 3: the 3rd line cross the 1st line
			if(i >= 3){
				if(x[i - 1] <= x[i - 3] && x[i] >= x[i - 2]){
					return true;
				}
			}
			// i >= 4: the 4th line cross the 1st line
			if(i >= 4){
				if(x[i - 3] == x[i - 1] && x[i - 4] + x[i] >= x[i - 2]){
					return true;
				}
			}
			// i >= 5: the 5th line cross the 1st line
			if(i >= 5){
				if(x[i - 3] >= x[i - 1] && x[i - 3] <= x[i - 5] + x[i - 1] && x[i - 2] >= x[i - 4] && x[i - 2] <= x[i - 4] + x[i]){
					return true;
				}
			}
		}
		return false;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> x = {1, 2, 3, 4};
	cout << "ans: " << sol.isSelfCrossing(x) << endl;
	return 0;
}
