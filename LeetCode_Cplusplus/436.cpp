#include<bits/stdc++.h>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0){}
	Interval(int s, int e): start(s), end(e){}
};

// binary search
class Solution {
private: 
	// sort by start and index
	static int cmp(const pair<int, int> &p1, const pair<int, int> &p2){
		if(p1.first != p2.first){
			return p1.first < p2.first;
		}
		return p1.second < p2.second;
	}

public:
    vector<int> findRightInterval(vector<Interval>& intervals) {
		int n = intervals.size();
		if(!n){
			return vector<int>();
		}
        vector<int> ans;
		vector<pair<int, int>> vec;
		for(int i = 0; i <= n - 1; i++){
			vec.push_back(make_pair(intervals[i].start, i));
		}
		// sort
		sort(vec.begin(), vec.end(), cmp);
		// binary search
		for(int i = 0; i <= n - 1; i++){
			int target = intervals[i].end;
			int left = 0, right = n - 1;
			while(left <= right){
				int mid = left + ((right -left) >> 1);
				if(vec[mid].first < target){
					left = mid + 1;
				}
				else{
					right = mid - 1;
				}
			}
			ans.push_back(left == n? -1: vec[left].second);
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<Interval> intervals = {{3, 4}, {2, 3}, {2, 2}, {1, 2}};
	vector<int> ans = sol.findRightInterval(intervals);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
