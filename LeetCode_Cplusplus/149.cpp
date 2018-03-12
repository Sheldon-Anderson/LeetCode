#include<bits/stdc++.h>
using namespace std;

struct Point{
	int x;
	int y;
	Point(): x(0), y(0){}
	Point(int a, int b): x(a), y(b){}
};

// map
class Solution {
private: 
	static int cmp(const Point a, const Point b){
		if(a.x != b.x){
			return a.x < b.x;
		}
		return a.y < b.y;
	}

public:
    int maxPoints(vector<Point>& points) {
        int n = points.size();
		if(n <= 2){
			return n;
		}
		int ans = 0;
		// sort
		sort(points.begin(), points.end(), cmp);
		// get gradients
		for(int i = 0; i <= n - 2; i++){
			map<double, int> m;
			// points on the same position
			int cnt_same_XY = 0;
			// points on the same vertical line
			int cnt_same_X = 1;
			for(int j = i + 1; j <= n - 1; j++){
				if(points[i].x == points[j].x && points[i].y == points[j].y){
					cnt_same_XY++;
					cnt_same_X++;
				}
				else if(points[i].x == points[j].x && points[i].y != points[j].y){
					cnt_same_X++;
				}
				else{
    				double k = 1.0 * (points[i].y - points[j].y) / (points[i].x - points[j].x);
    				if(!m.count(k)){
    					m[k] = 2;
    				}
    				else{
    					m[k]++;
    				}
    				// update ans 1
    				ans = max(ans, m[k] + cnt_same_XY);				    
				}
			}
			// update ans 2
			ans = max(ans, cnt_same_X);
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<Point> points = {{1, 1}, {2, 2}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {3, 2}, {5, 3}, {2, 1}, {2, 3}, {2, 4}};
	cout << "ans: " << sol.maxPoints(points) << endl;
	return 0;
}
