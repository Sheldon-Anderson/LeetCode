#include<bits/stdc++.h>

using namespace std;

/*
	math problem: 
	=> we suppose A save all numbers in nums from large to small, 
	   so steps = (A[0] - A[n - 1]) + (A[1] - A[n - 1]) + (A[2] - A[n - 1]) + ...+ (A[n - 1] - A[n - 1])
				= sum(A) - n * A[n - 1]
*/
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
		int minVal = *min_element(nums.begin(), nums.end());
		return sum - nums.size() * minVal;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 2, 3, 4};
	cout << "ans: " << sol.minMoves(nums) << endl;
	return 0;
}
