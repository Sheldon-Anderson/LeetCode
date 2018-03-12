#include<bits/stdc++.h>

using namespace std;

// binary search + greedy
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n1 = g.size(), n2 = s.size();
		if(!n1 || !n2){
			return 0;
		}
		// sort by increasing
		sort(s.begin(), s.end(), less<int>());
		// binary search
		int ans = 0;
		for(int i = 0; i <= n1 - 1; i++){
			n2 = s.size();
			if(!n2){
				break;
			}
			int left = 0, right = n2 - 1;
			while(left <= right){
				int mid = left + ((right - left) >> 1);
				if(s[mid] < g[i]){
					left = mid + 1;
				}
				else{
					right = mid - 1;
				}
			}
			if(left <= n2 - 1){
				ans++;
				s.erase(s.begin() + left);
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> g = {1, 2, 4}, s = {1, 2, 3};
	cout << "ans: " << sol.findContentChildren(g, s) << endl;
	return 0;
}
