#include<bits/stdc++.h>

using namespace std;

/*
// unordered_map
// Memory Limit Exceeded 
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        int n = points.size();
		if(n <= 2){
			return 0;
		}
		unordered_map<int, unordered_map<int, int>> m;
		for(int i = 0; i <= n - 2; i++){
			for(int j = i + 1; j <= n - 1; j++){
				int squareDis = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
				m[i][squareDis]++;
				m[j][squareDis]++;
			}
		}
		// get answer
		int ans = 0;
		for(int i = 0; i <= m.size() - 1; i++){
			for(auto &p: m[i]){
				ans += p.second * (p.second - 1);
			}
		}
		return ans;
    }
};
*/

/*
// unordered_map
// Accepted
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int n = points.size();
		if(n <= 2){
			return 0;
		}
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			// map from distance to its count
			unordered_map<int, int> m;
			for(int j = 0; j <= n - 1; j++){
				if(i == j){
					continue;
				}
				int squareDis = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
				m[squareDis]++;
			}
			// update answer
			for(auto &p: m){
				ans += p.second * (p.second - 1);
			}
		}
		// get answer
		return ans;
	}
};
*/

// map
class Solution {
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
		int n = points.size();
		if(n <= 2){
			return 0;
		}
		int ans = 0;
		for(int i = 0; i <= n - 1; i++){
			// map from distance to its count
			map<int, int> m;
			for(int j = 0; j <= n - 1; j++){
				if(i == j){
					continue;
				}
				int squareDis = (points[i].first - points[j].first) * (points[i].first - points[j].first) + (points[i].second - points[j].second) * (points[i].second - points[j].second);
				m[squareDis]++;
			}
			// update answer
			for(auto &p: m){
				ans += p.second * (p.second - 1);
			}
		}
		// get answer
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<pair<int, int>> points = {{0, 0}, {1, 0}, {2, 0}, {0, 1}, {0, 2}};
	cout << "ans: " << sol.numberOfBoomerangs(points) << endl;
	return 0;
}
