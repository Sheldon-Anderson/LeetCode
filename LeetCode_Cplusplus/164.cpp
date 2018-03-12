#include<bits/stdc++.h>
using namespace std;

/*
// Accepted
// sort (STL)
// T(n) = O(nlogn)
class Solution {
private: 
	static int cmp(const int a, const int b){
		return a < b;
	}

public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
		if(n <= 1){
			return 0;
		}
		// sort
		sort(nums.begin(), nums.end(), cmp);
		// get answer
		int ans = 0;
		for(int i = 1; i <= n - 1; i++){
			ans = max(ans, nums[i] - nums[i - 1]);
		}
		return ans;
    }
};
*/

// radix sort
// T(n) = O(n)
class Solution{
public:
    int maximumGap(vector<int>& nums) {
		int n = nums.size();
		if(n <= 1){
			return 0;
		}
		// get max value
		int maxVal = INT_MIN;
		for(int val: nums){
			maxVal = max(maxVal, val);
		}
		// radix and exp
		int radix = 10;
		int exp = 1;
		int *next = new int[n];
		int *count = new int[radix];
		// radix sort
		while(maxVal / exp > 0){
			memset(next, 0, sizeof(int) * n);
			memset(count, 0, sizeof(int) * radix);
			for(int i = 0; i <= n - 1; i++){
				count[(nums[i] / exp) % 10]++;
			}
			for(int i = 1; i <= radix - 1; i++){
				count[i] += count[i - 1];
			}
			for(int i = n - 1; i >= 0; i--){
				next[--count[(nums[i] / exp) % 10]] = nums[i];
			}
			for(int i = 0; i <= n - 1; i++){
				nums[i] = next[i];
			}
			exp *= 10;
		}
		// get answer
		int ans = 0;
		for(int i = 1; i <= n - 1; i++){
			ans = max(ans, nums[i] - nums[i - 1]);
		}
		return ans;
	}
};

int main(){
	Solution sol;
	vector<int> nums = {4, 2, 3, 1, 12, 7};
	cout << "ans: " << sol.maximumGap(nums) << endl;
	return 0;
}
