#include<bits/stdc++.h>
using namespace std;

// Topological Sort (stack)
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> ans;
        int n = prerequisites.size();
		// Exceptional Case: 
		if(n == 0){
			for(int i = 0; i <= numCourses - 1; i++){
				ans.push_back(i);
			}
			return ans;
		}
		// create and init
		map<int, set<int>> path;
		vector<int> in_degree(numCourses, 0);
		// save paths
		for(pair<int, int> p: prerequisites){
			int e = p.first, s = p.second;
			in_degree[e]++;
			path[s].insert(e);
		}
		// Topological Sort
		stack<int> st;
		int count = 0;
		for(int i = 0; i <= numCourses - 1; i++){
			if(!in_degree[i]){
				st.push(i);
			}
		}
		while(!st.empty()){
			int key = st.top();
			st.pop();
			ans.push_back(key);
			count++;
 			for(auto its = path[key].begin(); its != path[key].end(); its++){
				int val = *its;
				if(!--in_degree[val]){
					st.push(val);
				}
			}
		}
		if(count == numCourses){
			return ans;
		}
		return vector<int>();
    }
};

int main(){
	Solution sol;
	int numCourses = 8;
	vector<pair<int, int>> prerequisites = {{1, 0}, {3, 2}, {5, 4}, {7, 6}, {6, 7}};
	vector<int> ans = sol.findOrder(numCourses, prerequisites);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
