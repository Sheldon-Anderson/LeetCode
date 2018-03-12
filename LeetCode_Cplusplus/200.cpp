#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
private: 
	int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	void DFS(vector<vector<char>>& grid, int m, int n, int x, int y){
		for(int i = 0; i <= 3; i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n - 1 && grid[xx][yy] == '1'){
				grid[xx][yy] = '0';
				DFS(grid, m, n, xx, yy);
			}
		}
	}

public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty()){
			return 0;
		}
		int m = grid.size(), n = grid[0].size();
		if(m == 0 || n == 0){
			return 0;
		}
		int ans = 0;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				if(grid[i][j] == '1'){
					grid[i][j] = '0';
					ans++;
					DFS(grid, m, n, i, j);
				}
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<char>> grid = {
		{'1', '1', '1', '0', '0'},
		{'1', '1', '0', '0', '0'},
		{'0', '1', '1', '0', '0'},
		{'0', '0', '1', '1', '1'}
	};
	cout << "ans: " << sol.numIslands(grid) << endl;
	return 0;
}
