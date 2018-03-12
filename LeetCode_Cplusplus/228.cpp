#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
		int n = nums.size();
		if(n == 0){
			return ans;
		}
		stringstream stream;
		string s1, s2;
		int left = 0, right = 0;
		while(left <= right && right <= n - 1){
			while(right + 1 <= n - 1 && nums[right] + 1 == nums[right + 1]){
				right++;
			}
			stream << nums[left];
			stream >> s1;
			stream.clear();
			if(nums[left] == nums[right]){
				ans.push_back(s1);
			}
			else{
				stream << nums[right];
				stream >> s2;
				stream.clear();
				ans.push_back(s1 + "->" + s2);
			}
			left = right + 1;
			right = left;
		}
		return ans;
    }
};

int main(int argc, char *argv[]){
	Solution sol;
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7};
	vector<string> ans = sol.summaryRanges(nums);
	// console output
	for(string str: ans){
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
