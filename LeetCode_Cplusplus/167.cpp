#include<bits/stdc++.h>
using namespace std;

// sorted in ascending order
// binary search
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
		if(n <= 1){
			return vector<int>();
		}
		int left, right;
		vector<int> ans;
		for(int i = 0; i <= n - 1; i++){
			if(target - numbers[i] < numbers[i]){
				left = 0;
				right = i - 1;
			}
			// numbers = {0, 0, 3, 4}, target = 0
			else if(target - numbers[i] >= numbers[i]){
				left = i + 1;
				right = n - 1;
			}
			// binary search
			while(left <= right){
				int mid = (left + right) >> 1;
				if(numbers[mid] == target - numbers[i]){
					if(mid > i){
						swap(mid, i);
					}
					ans.push_back(mid + 1);
					ans.push_back(i + 1);
					break;
				}
				else if(numbers[mid] > target - numbers[i]){
					right = mid - 1;
				}
				else{
					left = mid + 1;
				}
			}
			if(ans.size()){
				break;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> numbers = {0, 0, 3, 4};	// {2, 7, 11, 16};
	int target = 0;	// 13;
	vector<int> ans = sol.twoSum(numbers, target);
	// console output
	cout << ans[0] << ", " << ans[1] << endl;
	return 0;
}
