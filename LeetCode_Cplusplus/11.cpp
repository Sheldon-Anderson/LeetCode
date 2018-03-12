#include<bits/stdc++.h>
using namespace std;

// two pointers
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
		// Exceptional Case: 
		if(n <= 1){
			return 0;
		}
		int ans = 0;
		int left = 0, right = n - 1;
		while(left < right){
			// debug
			// cout << "left: " << left << ", right: " << right << endl;
			int min_height = min(height[left], height[right]);
			ans = max(ans, min_height * (right - left));
			while(left <= n - 2 && height[left] <= min_height){
				left++;
			}
			while(right >= 1 && height[right] <= min_height){
				right--;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<int> height = {1, 1};
	cout << "ans: " <<  sol.maxArea(height) << endl;
	return 0;
}
