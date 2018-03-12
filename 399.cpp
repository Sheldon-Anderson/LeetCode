#include <bits/stdc++.h>
using namespace std;

// DFS + map
class Solution {
private: 
	bool get;
	double INF = numeric_limits<double>::infinity();
	vector<double> ans;
	map<string, map<string, double>> m;
	
	void DFS(string a, string b, string str, double res){
		// debug
		// cout << "str: " << str << ", res: " << res << endl;
		if(get){
			return;
		}
		if(str == b){
			ans.push_back(res);
			get = true;
			return;
		}
		for(auto p: m[str]){
			if(p.second == INF){
				continue;
			}
			double pre;
			if(m.count(p.first) && m[p.first].count(str)){
				pre = m[p.first][str];
				m[p.first][str] = INF;
			}
			DFS(a, b, p.first, res * p.second);
			if(m.count(p.first) && m[p.first].count(str)){
				m[p.first][str] = pre;
			}
		}
	}

public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        int n = equations.size();
		int N = queries.size();
		ans.clear();
		// Exceptional Case: 
		if(!n){
			if(N){
				return vector<double>(N, -1.0);
			}
			return vector<double>();
		}
		// get map
		for(int i = 0; i <= n - 1; i++){
			pair<string, string> p1 = equations[i];
			m[p1.first][p1.second] = values[i];
			if(values[i] != 0){
				m[p1.second][p1.first] = 1.0 / values[i];
			}
		}
		// DFS
		for(auto q: queries){
			if(!m.count(q.first) || !m.count(q.second)){
				ans.push_back(-1.0);
			}
			else if(q.first == q.second){
				ans.push_back(1.0);
			}
			else{
				get = false;
				DFS(q.first, q.second, q.first, 1.0);
				if(!get){
					ans.push_back(-1.0);
				}
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	// vector<pair<string, string>> equations = {{"x1", "x2"}, {"x2", "x3"}, {"x3", "x4"}, {"x4","x5"}};
	// vector<double> values = {3.0, 4.0, 5.0, 6.0};
	// vector<pair<string, string>> queries = {{"x1", "x5"}, {"x5", "x2"}, {"x2", "x4"}, {"x2", "x2"}, {"x2", "x9"}, {"x9", "x9"}};
	vector<pair<string, string>> equations = {{"a", "b"}, {"c", "d"}};
	vector<double> values = {1.0, 1.0};
	vector<pair<string, string>> queries = {{"a", "c"}, {"b", "d"}, {"b", "a"}, {"d", "c"}};
	vector<double> ans = sol.calcEquation(equations, values, queries);
	// console output
	for(double val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}

