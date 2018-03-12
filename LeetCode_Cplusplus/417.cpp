#include<bits/stdc++.h>

using namespace std;

// BFS
// Accepted
class Solution {
private: 
	int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
	vector<vector<int>> mark;

	void BFS(vector<vector<int>>& matrix, int m, int n, int sx, int sy){
		int s_pos = mark[sx][sy];
		queue<pair<int, int>> q;
		pair<int, int> p;
		q.push(make_pair(sx, sy));
		// queue
		while(!q.empty()){
			p = q.front();
			q.pop();
			int x = p.first, y = p.second;
			for(int i = 0; i <= 3; i++){
				int xx = x + dir[i][0], yy = y + dir[i][1];
				// check
				if(xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n - 1 && matrix[xx][yy] >= matrix[x][y]){
					if(s_pos == 3 && mark[xx][yy] != 3){
						mark[xx][yy] = 3;
						q.push(make_pair(xx, yy));
					}
					else if(s_pos == 1 && (mark[xx][yy] == 0 || mark[xx][yy] == 2)){
						mark[xx][yy] += 1;
						q.push(make_pair(xx, yy));
					}
					else if(s_pos == 2 && (mark[xx][yy] == 0 || mark[xx][yy] == 1)){
						mark[xx][yy] += 2;
						q.push(make_pair(xx, yy));
					}
				}
			}
		}
	}

public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()){
			return vector<pair<int, int>>();
		}
		int m = matrix.size(), n = matrix[0].size();
		// create and init
		mark.resize(m, vector<int>(n, 0));
		// Pacific
		mark[0][0] += 1;
		for(int i = 1; i <= m - 1; i++){
			mark[i][0] += 1;
		}
		for(int i = 1; i <= n - 1; i++){
			mark[0][i] += 1;
		}
		// Atlantic
		mark[m - 1][n - 1] += 2;
		for(int i = 0; i <= m - 2; i++){
			mark[i][n - 1] += 2;
		}
		for(int i = 0; i <= n - 2; i++){
			mark[m - 1][i] += 2;
		}
		// BFS
		for(int i = 0; i <= m - 1; i++){
			BFS(matrix, m, n, i, 0);
			BFS(matrix, m, n, i, n - 1);
		}
		for(int i = 1; i <= n - 2; i++){
			BFS(matrix, m, n, 0, i);
			BFS(matrix, m, n, m - 1, i);
		}
		// get answer
		vector<pair<int, int>> ans;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				if(mark[i][j] == 3){
					ans.push_back(make_pair(i, j));
				}
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> matrix = {
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
	    {5, 1, 1, 2, 4}		
	};
	vector<pair<int, int>> ans = sol.pacificAtlantic(matrix);
	// console output
	for(auto p: ans){
		cout << p.first << ", " << p.second << endl;
	}
	return 0;
}
