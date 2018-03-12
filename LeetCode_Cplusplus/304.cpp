#include <bits/stdc++.h>
using namespace std;

// dynamic programming
// sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + A[i][j];
// sum[r1, c1, r2, c2] = sum[r2][c2] - sum[r2][c1 - 1] - sum[r1 - 1][c2] + sum[r1 - 1][c1 - 1]
class NumMatrix {
private: 
	vector<vector<int>> A;
	int **sum;

public:
    NumMatrix(vector<vector<int>> matrix) {
        A = matrix;
		int m = matrix.size();
		if(m != 0){
			int n = matrix[0].size();
			if(n != 0){
				// create
				sum = new int*[m];
				for(int i = 0; i <= m - 1; i++){
					sum[i] = new int[n];
				}
				// init
				sum[0][0] = A[0][0];
				for(int i = 1; i <= n - 1; i++){
					sum[0][i] = sum[0][i - 1] + A[0][i];
				}
				for(int i = 1; i <= m - 1; i++){
					sum[i][0] = sum[i - 1][0] + A[i][0];
				}
				// DP
				for(int i = 1; i <= m - 1; i++){
					for(int j = 1; j <= n - 1; j++){
						sum[i][j] = sum[i][j - 1] + sum[i - 1][j] - sum[i - 1][j - 1] + A[i][j];
					}
				}
			}
		}
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = sum[row2][col2];
		if(col1 - 1 >= 0){
			ans -= sum[row2][col1 - 1];
		}
		if(row1 - 1 >= 0){
			ans -= sum[row1 - 1][col2];
		}
		if(col1 -1 >= 0 && row1 - 1 >= 0){
			ans += sum[row1 - 1][col1 - 1];
		}
		return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */
 
int main(int argc, char** argv){
	vector<vector<int>> matrix = {
		{3, 0, 1, 4, 2},
		{5, 6, 3, 2, 1},
		{1, 2, 0, 1, 5},
		{4, 1, 0, 1, 7},
		{1, 0, 3, 0, 5}
	};
	NumMatrix nm(matrix);
	int row1, col1, row2, col2;
	while(cin >> row1 >> col1 >> row2 >> col2){
		cout << "ans: " << nm.sumRegion(row1, col1, row2, col2) << endl;
	}
	return 0;
}
