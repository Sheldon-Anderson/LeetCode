#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        if(!grid.size() || !grid[0].size()){
			return 0;
		}
		int m = grid.size(), n = grid[0].size();
		int cnt = 0, neighbors = 0;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				if(grid[i][j] == 1){
					cnt++;
					if(i - 1 >= 0 && grid[i - 1][j] == 1){
						neighbors++;
					}
					if(j - 1 >= 0 && grid[i][j - 1] == 1){
						neighbors++;
					}
				}
			}
		}
		// get answer
		return cnt * 4 - neighbors * 2;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> grid = {
		{0, 1, 0, 0},
		{1, 1, 1, 0},
		{0, 1, 0, 0},
		{1, 1, 0, 0}
	};
	cout << "and: " << sol.islandPerimeter(grid) << endl;
	return 0;
}
