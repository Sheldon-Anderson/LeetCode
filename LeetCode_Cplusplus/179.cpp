#include<bits/stdc++.h>
using namespace std;

// cmp function: return s1 + s2 > s2 + s1;
class Solution {
private: 
	static int cmp(const string s1, const string s2){
		return s1 + s2 > s2 + s1;
	}

public:
    string largestNumber(vector<int>& nums) {
        string ans = "";
		int n = nums.size();
		if(n == 0){
			return ans;
		}
        string str;
		stringstream stream;
		vector<string> vec;
		for(int i = 0; i <= n - 1; i++){
			stream << nums[i];
			stream >> str;
			stream.clear();
			vec.push_back(str);
		}
		// sort
		sort(vec.begin(), vec.end(), cmp);
		// get answer
		for(string str: vec){
			ans += str;
		}
		// check if ans is "0"
		int pos = -1;
		for(int i = 0; i <= ans.length() - 1; i++){
			if(ans[i] != '0'){
				pos = i;
				break;
			}
		}
		if(pos == -1){
			return "0";
		}
		return ans.substr(pos, ans.length() - pos);
    }
};

int main(){
	Solution sol;
	vector<int> nums = {3, 30, 34, 5, 9};
	cout << "ans: " << sol.largestNumber(nums) << endl;
	return 0;
}
