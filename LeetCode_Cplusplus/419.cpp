#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        if(!board.size() || !board[0].size()){
			return 0;
		}
		int m = board.size(), n = board[0].size();
		int ans = 0;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				if(board[i][j] == 'X' && (i - 1 < 0 || board[i - 1][j] == '.') && (j - 1 < 0 || board[i][j - 1] == '.')){
					ans++;
				}
			}
		}
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<char>> board = {
		{'X', '.', '.', 'X'},
		{'.', '.', '.', 'X'},
		{'.', '.', '.', 'X'}
	};
	cout << "ans: " << sol.countBattleships(board) << endl;
	return 0;
}
