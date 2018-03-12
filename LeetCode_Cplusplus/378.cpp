#include <bits/stdc++.h>
using namespace std;

/*
// multiset
// Accepted
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		int ans = -1;
        if(k <= 0){
			return ans;
		}
		int m = matrix.size();
		if(m == 0){
			return ans;
		}
		int n = matrix[0].size();
		if(n == 0){
			return ans;
		}
		// multiset
		multiset<int> ms;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				ms.insert(matrix[i][j]);
				if(ms.size() > k){
					auto itms = ms.end();
					itms--;
					ms.erase(itms);
				}
			}
		}
		// get answer
		return *ms.crbegin();
    }
};
*/

// binary_search
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
		if(k <= 0){
			return -1;
		}
		int m = matrix.size();
		if(m == 0){
			return -1;
		}
		int n = matrix[0].size();
		if(n == 0){
			return -1;
		}
		if(k > m * n){
			return -1;
		}
		vector<int> ans;
		for(int i = 0; i <= m - 1; i++){
			for(int j = 0; j <= n - 1; j++){
				// binary_search
				int left = 0, right = ans.size() - 1;
				while(left <= right){
					int mid = left + ((right - left) >> 1);
					if(ans[mid] <= matrix[i][j]){
						left = mid + 1;
					}
					else{
						right = mid - 1;
					}
				}
				ans.insert(ans.begin() + left, matrix[i][j]);
				if(ans.size() > k){
					ans.pop_back();
				}
			}
		}
		// get answer
		return ans[k - 1];
	}
};

int main(int argc, char** argv){
	Solution sol;
	vector<vector<int>> matrix = {
		{1,  5,  9},
		{10, 11, 13},
		{12, 13, 15}
	};
	int k = 8;
	cout << "ans: " << sol.kthSmallest(matrix, k) << endl;
	return 0;
}
