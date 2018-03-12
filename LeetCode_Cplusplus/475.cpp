#include<bits/stdc++.h>

using namespace std;

// binary_search
class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
		if(!houses.size()){
			return 0;
		}
		if(!heaters.size()){
			return -1;
		}
		// sort
		sort(heaters.begin(), heaters.end(), less<int>());
		// binary_search
		int ans = 0;
		for(int target: houses){
			int delta = INT_MAX;
			int left = 0, right = heaters.size() - 1;
			while(left <= right){
				int mid = left + ((right - left) >> 1);
				delta = min(delta, abs(heaters[mid] - target));
				if(!delta){
					break;
				}
				if(heaters[mid] > target){
					right = mid - 1;
				}
				else if(heaters[mid] < target){
					left = mid + 1;
				}
			}
			ans = max(ans, delta);
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> houses = {1, 2, 3, 4}, heaters = {1};
	cout << "ans: " << sol.findRadius(houses, heaters) << endl;
	return 0;
}
