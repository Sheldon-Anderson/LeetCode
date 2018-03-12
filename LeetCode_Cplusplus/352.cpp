#include <bits/stdc++.h>

using namespace std;

struct Interval{
	int start;
	int end;
	Interval(): start(0), end(0){}
	Interval(int s, int e): start(s), end(e){}
};

class SummaryRanges {
private: 
	vector<Interval> vec;

public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        int n = vec.size();
		if(n == 0){
			vec.push_back(Interval(val, val));
		}
		else{
			bool hit = false;
			int pos = -1;
			for(int i = 0; i <= n - 1; i++){
				if(val >= vec[i].start && val <= vec[i].end){
					hit = true;
					pos = i;
					break;
				}
				else if(val < vec[i].start){
					pos = i;
					break;
				}
			}
			if(pos == -1){
				if(val == vec[n - 1].end + 1){
					vec[n - 1].end++;
				}
				else{
					vec.push_back(Interval(val, val));
				}
			}
			else if(!hit){
				if(pos == 0){
					if(val == vec[0].start - 1){
						vec[0].start--;
					}
					else{
						vec.insert(vec.begin(), Interval(val, val));
					}
				}
				else{
					if(val == vec[pos - 1].end + 1 && val == vec[pos].start - 1){
						vec[pos].start = vec[pos - 1].start;
						vec.erase(vec.begin() + pos - 1);
					}
					else if(val == vec[pos].start - 1){
						vec[pos].start--;
					}
					else if(val == vec[pos - 1].end + 1){
						vec[pos - 1].end++;
					}
					else{
						vec.insert(vec.begin() + pos,Interval(val, val));
					}
				}
			}
		}
    }
    
    vector<Interval> getIntervals() {
        return vec;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
 
int main(int argc, char** argv){
	SummaryRanges sr;
	vector<int> List = {1, 3, 7, 2, 6, 9, 4, 10, 5};
	for(int l: List){
		sr.addNum(l);
		vector<Interval> ans = sr.getIntervals();
		// console output
		for(Interval p: ans){
			cout << p.start << ", " << p.end << " ";
		}
		cout << endl;
	}
	return 0;
}
