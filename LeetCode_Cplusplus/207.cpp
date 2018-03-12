#include<bits/stdc++.h>
using namespace std;

// Topological Sort (stack)
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int n = prerequisites.size();
		if(n <= 1){
			return true;
		}
		// create and init
		map<int, set<int>> path;
		int *in_degree = new int[numCourses];
		memset(in_degree, 0, sizeof(int) * numCourses);
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
			count++;
			for(auto its = path[key].begin(); its != path[key].end(); its++){
				int val = *its;
				if(!--in_degree[val]){
					st.push(val);
				}
			}
		}
		// get answer
		return count == numCourses;
    }
};

int main(){
	Solution sol;
	int numCourses = 8;
	vector<pair<int, int>> prerequisites = {{1, 0}, {3, 2}, {5, 4}, {7, 6}, {6, 7}};
	cout << "ans: " << sol.canFinish(numCourses, prerequisites) << endl;
	return 0;
}
