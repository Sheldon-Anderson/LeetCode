#include <bits/stdc++.h>

using namespace std;

// DFS + map
class Solution {
private: 
	vector<string> ans;
	map<string, map<string, int>> path;
	
	bool DFS(int n, string start){
		if(ans.size() == (n + 1)){
			return true;
		}
		// for(auto p: path[start]){ will cause an error!
		for(auto &p: path[start]){
			if(p.second){
				p.second--;
				ans.push_back(p.first);
				if(DFS(n, p.first)){
					return true;
				}
				ans.pop_back();
				p.second++;
			}
		}
		return false;
	}

public:
    vector<string> findItinerary(vector<pair<string, string>> tickets) {
		ans.clear();
		path.clear();
		// get path
		for(auto p: tickets){
			path[p.first][p.second]++;
		}
		// DFS
		ans.push_back("JFK");
		DFS(tickets.size(), "JFK");
		return ans;
    }
};

int main(int agrc, char** argv){
	Solution sol;
	// {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
	vector<pair<string, string>> tickets = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
	vector<string> ans =  sol.findItinerary(tickets);
	// out
	for(string str: ans){
		cout << str << " ";
	}
	cout << endl;
	return 0;
}
