#include<bits/stdc++.h>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0){}
	Interval(int s, int e): start(s), end(e){}
};

// Greedy
class Solution {
private: 
	// sort compare function
	static int cmp(const Interval &a, const Interval &b){
		if(a.end != b.end){
			return a.end < b.end;
		}
		return a.start < b.start;
	}

public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        int n = intervals.size();
		if(n <= 1){
			return 0;
		}
		// sort
		sort(intervals.begin(), intervals.end(), cmp);
		// greedy
		int ans = 0;
		for(int i = 1; i <= n - 1; i++){
			bool flag = false;
			for(int j = i - 1; j >= 0; j--){
				if(intervals[j].start != -1 && intervals[j].end != -1 && intervals[i].start < intervals[j].end){
					flag = true;
					break;
				}
			}
			if(flag){
				intervals[i].start = intervals[i].end = -1;
				ans++;
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<Interval> intervals = {{1, 2}, {2, 3}};	// {{1, 2}, {1, 2}, {1, 2}};	// {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
	cout << "ans: " << sol.eraseOverlapIntervals(intervals) << endl;
	return 0;
}
