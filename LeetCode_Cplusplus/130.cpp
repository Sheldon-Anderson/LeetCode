#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
private: 
	int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

	void DFS(vector<vector<char>>& board, int m, int n, int x, int y){
		for(int i = 0; i <= 3; i++){
			int xx = x + dir[i][0];
			int yy = y + dir[i][1];
			// if(xx >= 0 && xx <= m - 1 && yy >= 0 && yy <= n - 1 && board[xx][yy] == 'O'){ will cause a Runtime Error!
			if(xx >= 1 && xx <= m - 2 && yy >= 1 && yy <= n - 2 && board[xx][yy] == 'O'){
				board[xx][yy] = 'Y';
				DFS(board, m, n, xx, yy);
			}
		}
	}

public:
    void solve(vector<vector<char>>& board) {
        if(board.empty()){
			return;
		}
		int m = board.size(), n = board[0].size();
		if(m == 0 || n == 0){
			return;
		}
		// DFS from the borders
		for(int i = 0; i <= n - 1; i++){
			if(board[0][i] == 'O'){
				board[0][i] = 'Y';
				DFS(board, m, n, 0, i);
			}
			if(board[m - 1][i] == 'O'){
				board[m - 1][i] = 'Y';
				DFS(board, m, n, m - 1, i);
			}
		}
		for(int i = 1; i <= m - 2; i++){
			if(board[i][0] == 'O'){
				board[i][0] = 'Y';
				DFS(board, m, n, i, 0);
			}
			if(board[i][n - 1] == 'O'){
				board[i][n - 1] = 'Y';
				DFS(board, m, n, i, n - 1);
			}
		}
		// get answer
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				if(board[i][j] == 'O'){
					board[i][j] = 'X';
				}
				else if(board[i][j] == 'Y'){
					board[i][j] = 'O';
				}
			}
		}
    }
};

int main(){
	Solution sol;
	vector<vector<char>> board = {
		{'X', 'X', 'X', 'X'},
		{'X', 'O', 'O', 'X'},
		{'X', 'X', 'O', 'X'},
		{'X', 'O', 'X', 'X'}
	};
	sol.solve(board);
	// console output
	for(int i = 0; i <= board.size() - 1; i++){
		for(int j = 0; j <= board[0].size() - 1; j++){
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
