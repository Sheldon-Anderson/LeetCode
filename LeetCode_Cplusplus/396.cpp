#include <bits/stdc++.h>
using namespace std;

/*
	sum(A) = a0 + a1 + a2 + ... + a(n - 1)
	F(i) - F(i - 1) = sum(A) - n * a(n - i), 1 <= i <= n - 1
*/
class Solution {
public:
    int maxRotateFunction(vector<int>& A) {
        int n = A.size();
		if(!n){
			return 0;
		}
		// get sum
		int sum = accumulate(A.begin(), A.end(), 0);
		// get F[0], F[1], F[2], ..., F[n - 1]
		int preF = 0, curF, ans;
		for(int i = 0; i <= n - 1; i++){
			preF += (i * A[i]);
		}
		ans = preF;
		for(int i = 1; i <= n - 1; i++){
			curF = preF + sum - n * A[n - i];
			ans = max(ans, curF);
			preF = curF;
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> A = {4, 3, 2, 6};
	cout << "ans: " << sol.maxRotateFunction(A) << endl;
	return 0;
}
