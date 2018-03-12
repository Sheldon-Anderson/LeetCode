#include<bits/stdc++.h>
using namespace std;

// stack + dynamic programming
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()){
			return 0;
		}
		int m = matrix.size(), n = matrix[0].size();
		if(m == 0 || n == 0){
			return 0;
		}
		// create and init
		// heights[m][n + 1]
		int **heights = new int*[m];
		for(int i = 0; i <= m - 1; i++){
			heights[i] = new int[n + 1];
		}
		for(int i = 0; i <= m - 1; i++){
			heights[i][n] = 0;
		}		
		for(int i = 0; i <= n - 1; i++){
			heights[0][i] = (matrix[0][i] == '0')? 0: 1;
		}
		for(int i = 1; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				heights[i][j] = (matrix[i][j] == '0')? 0: heights[i - 1][j] + 1;
			}
		}
		// stack
		int ans = 0;
		for(int i = 0; i <= m - 1; i++){
			stack<int> st;
			for(int j = 0; j <= n; j++){
				if(st.empty() || heights[i][j] >= heights[i][st.top()]){
					st.push(j);
				}
				else{
					int top = st.top();
					st.pop();
					int w = st.empty()? j: j - 1 - st.top();
					int minVal = min(heights[i][top], w);
					ans = max(ans, minVal * minVal);
					j--;
				}
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	vector<vector<char>> matrix	= {
		{'1', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1'},
		{'1', '1', '1', '1', '1'},
		{'1', '0', '0', '1', '0'}
	};
	cout << "ans: " << sol.maximalSquare(matrix) << endl;
	return 0;
}
