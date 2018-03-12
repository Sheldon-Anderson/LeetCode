#include<bits/stdc++.h>

using namespace std;

// stack
/*
	S1, S2, S3: S2 > S3 > S1
	1. int S3: keep the S3
	2. stack<int> st: keep the S2s > S3 (from buttom to up: large to small)
	3. if nums[i] < S3, then we get S1, return true
*/
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
		if(n <= 2){
			return false;
		}
		int S3 = INT_MIN;
		stack<int> st;
		for(int i = n - 1; i >= 0; i--){
			if(nums[i] < S3){
				return true;
			}
			while(!st.empty() && nums[i] > st.top()){
				S3 = st.top();
				st.pop();
			}
			st.push(nums[i]);
		}
		// get answer
		return false;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {3, 1, 4, 2};
	cout << "ans: " << sol.find132pattern(nums) << endl;
	return 0;
}
