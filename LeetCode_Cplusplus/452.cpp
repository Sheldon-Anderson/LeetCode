#include<bits/stdc++.h>

using namespace std;

// greedy + sort
class Solution {
private: 
	static int cmp(const pair<int, int> &p1, const pair<int, int> &p2){
		if(p1.second != p2.second){
			return p1.second < p2.second;
		}
		return p1.first < p2.first;
	}

public:
    int findMinArrowShots(vector<pair<int, int>>& points) {
        int n = points.size();
		if(n <= 1){
			return n;
		}
		// sort
		sort(points.begin(), points.end(), cmp);
		// greedy
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			// {-1, -1} means that it has been merged
			if(points[i].first != -1 || points[i].second != -1){
				ans++;
			}
			for(int j = i + 1; j <= n - 1; j++){
				if((points[j].first != -1 || points[j].second != -1) && points[j].first <= points[i].second){
					points[j].first = points[j].second = -1;
				}
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<pair<int, int>> points = {{-1, 1}, {0, 1}, {2, 3}, {1, 2}};	// {{10, 16}, {2, 8}, {1, 6}, {7, 12}, {14, 18}};
	cout << "ans: " << sol.findMinArrowShots(points) << endl;
	return 0;
}
