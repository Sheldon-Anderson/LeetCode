#include <bits/stdc++.h>
using namespace std;

// math + map
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        int m = rectangles.size();
		if(m <= 1){
			return true;
		}
		int n = rectangles[0].size();
		int x_min = INT_MAX, y_min = INT_MAX, x_max = INT_MIN, y_max = INT_MIN;
		int area = 0;
		map<pair<int, int>, int> mp;
		for(int i = 0; i <= m - 1; i++){
			mp[make_pair(rectangles[i][0], rectangles[i][1])]++;
			mp[make_pair(rectangles[i][2], rectangles[i][3])]++;
			mp[make_pair(rectangles[i][0], rectangles[i][3])]++;
			mp[make_pair(rectangles[i][2], rectangles[i][1])]++;
			area += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
			if(rectangles[i][0] <= x_min && rectangles[i][1] <= y_min){
				x_min = rectangles[i][0];
				y_min = rectangles[i][1];
			}
			if(rectangles[i][2] >= x_max && rectangles[i][3] >= y_max){
				x_max = rectangles[i][2];
				y_max = rectangles[i][3];
			}
		}
		// check 1
		if(area != (x_max - x_min) * (y_max - y_min)){
			return false;
		}
		// check 2
		int cnt_1 = 0, cnt_1_pos = 0;
		pair<int, int> p1(x_min, y_min), p2(x_max, y_max), p3(x_min, y_max), p4(x_max, y_min);
		for(auto &p: mp){
			if(p.second != 1 && p.second != 2 && p.second != 4){
				return false;
			}
			if(p.second == 1 && (p.first == p1 || p.first == p2 || p.first == p3 || p.first == p4)){
				cnt_1_pos++;
			}
			if(p.second == 1){
				cnt_1++;
			}
		};
		// get answer
		return cnt_1 == 4 && cnt_1_pos == 4;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> rectangles = {
		{0,0,1,1}, 
		{0,0,2,1}, 
		{1,0,2,1}, 
		{0,2,2,3}
	};

	cout << "ans: " << sol.isRectangleCover(rectangles) << endl;
	return 0;
}
