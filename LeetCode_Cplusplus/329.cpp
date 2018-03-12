#include <bits/stdc++.h>
using namespace std;

// DFS + memory
class Solution {
private: 
	int **memory;
	int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	
	int DFS(vector<vector<int>>& matrix, int m, int n, int x, int y){
		if(memory[x][y]){
			return memory[x][y];
		}
		int res = 1;
		for(int i = 0; i <= 3; i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			if(xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n - 1 && matrix[xx][yy] > matrix[x][y]){
				res = max(res, 1 + DFS(matrix, m, n, xx, yy));
			}
		}
		memory[x][y] = res;
		return res;
	}

public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m = matrix.size();
		if(m == 0){
			return 0;
		}
		int n = matrix[0].size();
		if(n == 0){
			return 0;
		}
		// create and init
		memory = new int*[m];
		for(int i = 0; i <= m - 1; i++){
			memory[i] = new int[n];
			memset(memory[i], 0, sizeof(int) * (n));
		}
		// DFS from every pos
		int ans = 0;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				ans = max(ans, DFS(matrix, m, n, i, j));
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> matrix = {
		// {9,9,4},
		// {6,6,8},
		// {2,1,1}
		{3,4,5},
		{3,2,6},
		{2,2,1}
	};
	cout << "ans: " << sol.longestIncreasingPath(matrix) << endl;
	return 0;
}
