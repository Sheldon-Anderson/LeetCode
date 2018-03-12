#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
	int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1,}, {1, 0}, {1, 1}};

public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
		if(m == 0){
			return;
		}
		int n = board[0].size();
		if(n == 0){
			return;
		}
		/* 
			0->0: 0
			0->1: 2
			1->1: 1
			1->0: 3
		*/
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				int cnt_live_neis = 0;
				for(int k = 0; k <= 7; k++){
					int x = i + dir[k][0];
					int y = j + dir[k][1];
					if((x >= 0 && x <= m - 1 && y >= 0 && y <= n - 1) && (board[x][y] == 1 || board[x][y] == 3)){
						cnt_live_neis++;
					}
				}
				if(board[i][j] == 1 && (cnt_live_neis < 2 || cnt_live_neis > 3)){
					board[i][j] = 3;
				}
				else if(board[i][j] == 0 && cnt_live_neis == 3){
					board[i][j] = 2;
				}
			}
		}
		// get answer
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				if(board[i][j] == 2){
					board[i][j] = 1;
				}
				else if(board[i][j] == 3){
					board[i][j] = 0;
				}
			}
		}
    }
};

int main(int argc, char** argv){
	
	return 0;
}
