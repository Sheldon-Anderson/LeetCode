#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
		for(int val: nums){
			if(s.count(val)){
				return true;
			}
			else{
				s.insert(val);
			}
		}
		return false;
    }
};

int main(){
	Solution sol;
	vector<int> nums = {1, 2, 2, 3, 4, 4};
	cout << "ans: " << sol.containsDuplicate(nums) << endl;
	return 0;
}
