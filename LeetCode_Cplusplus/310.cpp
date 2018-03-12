#include <bits/stdc++.h>
using namespace std;

// Topological Sort Variant
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
		vector<int> ans;
		if(n <= 2){
			for(int i = 0; i <= n - 1; i++){
				ans.push_back(i);
			}
			return ans;
		}
		// create and init
		map<int, vector<int>> m;
		int *degree = new int[n];
		memset(degree, 0 ,sizeof(int) * n);
		// get degrees of all nodes
        int N = edges.size();
		for(int i = 0; i <= N - 1; i++){
			int first = edges[i].first, second = edges[i].second;
			degree[first]++;
			degree[second]++;
			m[first].push_back(second);
			m[second].push_back(first);
		}
		// Topological init
		queue<int> q;
		int cnt = 0, pre = 0, cur = 0;		
		for(int i = 0; i <= n - 1; i++){
			if(degree[i] == 1){
				q.push(i);
				pre++;
			}
		}
		// count
		while(!q.empty()){
			cnt += pre;
			while(pre--){
				int top = q.front();
				q.pop();
				degree[top]--;
				for(int i = 0; i <= m[top].size() - 1; i++){
					if(!degree[m[top][i]]){
						continue;
					}
					if((--degree[m[top][i]]) == 1){
						q.push(m[top][i]);
						cur++;
					}
				}				
			}
			// there are no more than 2 nodes left, break out
			if(n - cnt <= 2){
				break;
			}
			pre = cur;
			cur = 0;
		}
		// get answer
		while(!q.empty()){
			int top = q.front();
			q.pop();
			ans.push_back(top);
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n = 6;	// 4;
	vector<pair<int, int>> edges = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};	// {{1, 0}, {1, 2}, {1, 3}};
	vector<int> ans = sol.findMinHeightTrees(n, edges);
	// console output
	for(int val: ans){
		cout << val << " ";
	}
	cout << endl;
	return 0;
}
