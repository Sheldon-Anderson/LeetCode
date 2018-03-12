#include<bits/stdc++.h>
using namespace std;

// binary search + DFS
class Solution {
private: 
	bool flag;
	
	void DFS(vector<vector<int>>& matrix, int target, int s1, int e1, int s2, int e2){
		// debug
		// cout << "s1:" << s1 << ", e1: " << e1 << ", s2: " << s2 << ", e2: " << e2 << endl;
		if(s1 > e1 || s2 > e2 || flag){
			return;
		}
		int x = (s1 + e1) / 2, y = (s2 + e2) / 2;
		if(matrix[x][y] == target){
			flag = true;
			return;
		}
		else if(matrix[x][y] < target){
			DFS(matrix, target, x + 1, e1, s2, y);
			DFS(matrix, target, s1, x, y + 1, e2);
			DFS(matrix, target, x + 1, e1, y + 1, e2);			
		}
		else if(matrix[x][y] > target){
			DFS(matrix, target, x, e1, s2, y - 1);
			DFS(matrix, target, s1, x - 1, y, e2);
			DFS(matrix, target, s1, x - 1, s2, y - 1);
		}
	}

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
		// Exceptional Case: 
		if(m == 0){
			return false;
		}
		int n = matrix[0].size();
		if(n == 0){
			return false;
		}
		flag = false;
		int s1 = 0, e1 = m - 1, s2 = 0, e2 = n - 1;
		DFS(matrix, target, s1, e1, s2, e2);
		return flag;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> matrix = {
		{1,   4,  7, 11, 15},
		{2,   5,  8, 12, 19},
		{3,   6,  9, 16, 22},
		{10, 13, 14, 17, 24},
		{18, 21, 23, 26, 30}
	};
	int target;
	while(cin >> target){
		cout << "ans: " << sol.searchMatrix(matrix, target) << endl;
	}
	return 0;
}
