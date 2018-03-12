#include<bits/stdc++.h>
using namespace std;

/*
	multiset<int> ms = {1, 2, 2, 2, 3, 3, 4, 4, 4, 5, 5, 5};
	
	// delete all the 2s
	ms.erase(2);
	
	// delete just one 4
	ms.erase(ms.find(4));
*/

class Solution {
private: 
	static int cmp(const pair<int, int> a, const pair<int, int> b){
		if(a.first != b.first){
			return a.first < b.first;
		}
		return a.second < b.second;
	}

public:
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        int n = buildings.size();
		// Exceptional Case: 
		if(n == 0){
			return vector<pair<int, int>>();
		}
		vector<pair<int, int>> vec, ans;
		multiset<int> mset;
		int pre_height = 0, cur_height = 0;
		// height < 0 means start, height > 0 means end
		for(int i = 0; i <= n - 1; i++){
			vec.push_back(make_pair(buildings[i][0], -buildings[i][2]));
			vec.push_back(make_pair(buildings[i][1], buildings[i][2]));
		}
		// sort
		sort(vec.begin(), vec.end(), cmp);
		// init
		mset.insert(pre_height);
		// heap manipulation
		for(auto &p: vec){
			if(p.second < 0){
				mset.insert(-p.second);
			}
			else{
				mset.erase(mset.find(p.second));
			}
			cur_height = *mset.rbegin();
			if(cur_height != pre_height){
				ans.push_back(make_pair(p.first, cur_height));
				pre_height = cur_height;
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<int>> buildings = {{2, 9, 10}, {3, 7, 15}, {5, 12, 12}, {15, 20, 10}, {19, 24, 8}};
	vector<pair<int, int>> ans = sol.getSkyline(buildings);
	// console output
	for(auto &p: ans){
		cout << p.first << ", " << p.second << endl;
	}
	return 0;
}
