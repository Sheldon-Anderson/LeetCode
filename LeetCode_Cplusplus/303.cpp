#include <bits/stdc++.h>
using namespace std;

class NumArray {
private: 
	vector<int> A;
	int *sum;

public:
    NumArray(vector<int> nums) {
        A = nums;
		int n = A.size();
		if(n != 0){
    		sum = new int[n];
    		sum[0] = A[0];
    		for(int i = 1; i <= n - 1; i++){
    			sum[i] = A[i] + sum[i - 1];
    		}
		}
    }
    
    int sumRange(int i, int j) {
        int n = A.size();
        if(n != 0){
            if(i == 0){
    			return sum[j];
    		}
    		return sum[j] - sum[i - 1];            
        }
		return -1;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * int param_1 = obj.sumRange(i,j);
 */
 
int main(int argc, char** argv){
	vector<int> nums = {-2, 0, 3, -5, 2, -1};
	NumArray na(nums);
	int i, j;
	while(cin >> i >> j){
		cout << "ans: " << na.sumRange(i, j) << endl;
	}
	return 0;
}
