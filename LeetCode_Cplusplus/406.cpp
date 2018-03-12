#include<bits/stdc++.h>

using namespace std;

// sort + insert
class Solution {
private: 
	// sort compare function
	static int cmp(const pair<int, int> &a, const pair<int, int> &b){
		if(a.first != b.first){
			return a.first > b.first;
		}
		return a.second < b.second;
	}

public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        int n = people.size();
		if(n <= 1){
			return people;
		}
		// sort
		sort(people.begin(), people.end(), cmp);
		// get answer
		vector<pair<int, int>> ans;
		for(pair<int, int> p: people){
			ans.insert(ans.begin() + p.second, p);
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<pair<int, int>> people = {{7, 0}, {4, 4}, {7, 1}, {5, 0}, {6, 1}, {5, 2}};
	vector<pair<int, int>> ans = sol.reconstructQueue(people);
	// console output
	for(auto p: ans){
		cout << p.first << ", " << p.second << endl;
	}
	return 0;
}
