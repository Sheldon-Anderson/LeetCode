#include <bits/stdc++.h>
using namespace std;

/*
	Ascending Sort: 
	iterator lower_bound( const key_type &key ): value >= key
	iterator upper_bound( const key_type &key ): value > key
	Descending Sort: 
	iterator lower_bound( const key_type &key ): value <= key
	iterator upper_bound( const key_type &key ): value < key
*/
/*
// binary_search + dynamic programming
// T(m, n) = O(m^2 * n * log(n))
// Accepted
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
		if(m == 0){
			return 0;
		}
		int n = matrix[0].size();
		if(n == 0){
			return 0;
		}
		int ans = INT_MIN;
		for(int i = 0; i <= m - 1; i++){
			// save all columns' sums from row j to row i
			vector<int> colSum(n, 0);
			for(int j = i; j >= 0; j--){
				set<int> s;
				int partialSum = 0;
				s.insert(0);
				for(int l = 0; l <= n - 1; l++){
					colSum[l] += matrix[j][l];
					partialSum += colSum[l];
					// binary_search: *its >= partialSum - k => partialSum - *its <= k
					auto its = s.lower_bound(partialSum - k);
					if(its != s.end()){
						ans = max(ans, partialSum - *its);
					}
					s.insert(partialSum);
				}
			}
		}
		// get answer
		return ans;
    }
};
*/

// binary_search + dynamic programming
/* 
	T(m, n) = 
		1. O(m^2 * n * log(n)), m <= n
		2. O(n^2 * m * log(m)), m > n
*/
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		// Exceptional Case: 
		int m = matrix.size();
		if(m == 0){
			return 0;
		}
		int n = matrix[0].size();
		if(n == 0){
			return 0;
		}
		// swap
		bool flag = false;
		if(m > n){
			swap(m, n);
			flag = true;
		}
		int ans = INT_MIN;
		for(int i = 0; i <= m - 1; i++){
			// save all columns' sums from row j to row i
			vector<int> colSum(n, 0);
			for(int j = i; j >= 0; j--){
				set<int> s;
				int partialSum = 0;
				s.insert(0);
				for(int l = 0; l <= n - 1; l++){
					colSum[l] += (flag? matrix[l][j]: matrix[j][l]);
					partialSum += colSum[l];
					// binary_search: *its >= partialSum - k =>partialSum - *its <= k
					auto its = s.lower_bound(partialSum - k);
					if(its != s.end()){
						ans = max(ans, partialSum - *its);
					}
					s.insert(partialSum);
				}
			}
		}
		// get answer
		return ans;
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> matrix = {
		{1, 0, 1},
		{0, -2, 3}
	};
	int k = 2;
	cout << "ans: " << sol.maxSumSubmatrix(matrix, k) << endl;
	return 0;
}
