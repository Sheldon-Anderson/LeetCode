#include<bits/stdc++.h>

using namespace std;

// binary search
class Solution {
private: 
	static int cmp(const int &a, const int &b){
		return a < b;
	}

public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        int N = A.size();
		if(!N){
			return 0;
		}
		vector<int> vec;
		// save the sums of elements from C and D
		for(int i = 0; i <= N - 1; i++){
			for(int j = 0; j <= N - 1; j++){
				vec.push_back(C[i] + D[j]);
			}
		}
		// sort
		sort(vec.begin(), vec.end(), cmp);
		// binary search
		int ans = 0;
		for(int i = 0; i <= N - 1; i++){
			for(int j = 0; j <= N - 1; j++){
				int left = 0, right = N * N - 1;
				int target = -A[i] - B[j];
				// find the first element in vec that > target
				while(left <= right){
					int mid = left + ((right - left) >> 1);
					if(vec[mid] <= target){
						left = mid + 1;
					}
					else{
						right = mid - 1;
					}
				}
				int R = left;
				// find the first element in vec that < target
				left = 0, right = N * N - 1;
				while(left <= right){
					int mid = left + ((right - left) >> 1);
					if(vec[mid] >= target){
						right = mid - 1;
					}
					else{
						left = mid + 1;
					}
				}
				int L = right;
				ans += (R - L - 1);
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> A = {1, 2}, B = {-2, -1}, C = {-1, 2}, D = {0, 2};
	cout << "ans: " << sol.fourSumCount(A, B, C, D) << endl;
	return 0;
}
