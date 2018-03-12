#include <bits/stdc++.h>
using namespace std;

// binary search
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
		if(n == 0){
			return 0;
		}
		int left = 1, right = n;
		while(left <= right){
			int mid = (left + right) >> 1;
			if(citations[n - mid] >= mid){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		return right;
    }
};

int main(int argc, char** argv){
	Solution sol;
	vector<int> citations = {0};	// {0, 1, 3, 5 ,6};		// {0, 0, 4, 4};
	cout << "ans: " << sol.hIndex(citations) << endl;
	return 0;
}
