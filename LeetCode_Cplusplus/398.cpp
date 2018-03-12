#include <bits/stdc++.h>
using namespace std;

// rand()
class Solution {
private: 
	vector<int> A;

public:
    Solution(vector<int> nums) {
        A = nums;
    }
    
    int pick(int target) {
		int n = A.size();
		if(!n){
			return -1;
		}
		vector<int> indices;
        for(int i = 0; i <= n - 1; i++){
			if(A[i] == target){
				indices.push_back(i);
			}
		}
		int N = indices.size();
		if(!N){
			return -1;
		}
		return indices[rand() % N];
    }
};

int main(int argc, char** argv){
	vector<int> nums = {1, 2, 3, 3, 3};
	Solution sol(nums);
	cout << "ans: " << sol.pick(3) << endl;
	cout << "ans: " << sol.pick(1) << endl;
	return 0;
}
