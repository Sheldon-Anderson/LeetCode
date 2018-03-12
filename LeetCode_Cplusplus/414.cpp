#include<bits/stdc++.h>

using namespace std;

// set
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
		if(!n){
			return -1;
		}
		set<int> s;
		for(int i = 0; i <= n - 1; i++){
			s.insert(nums[i]);
			if(s.size() > 3){
				s.erase(s.begin());
			}
		}
		// get answer
		if(s.size() < 3){
			return *s.crbegin();
		}
		return *s.cbegin();
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> nums = {1, 2, 2, 3};	// {1, 2, 3, 4, 5, 6, 7};
	cout << "ans: " << sol.thirdMax(nums) << endl;
	return 0;
}
