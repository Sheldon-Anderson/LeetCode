#include <bits/stdc++.h>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
	return true;
}

// binary search
class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
		while(left <= right){
			// int mid = (left + right) >> 1; will cause a Time Limit Exceeded
			// int mid = left + (right - left) >> 1; will cause an error!
			int mid = left + ((right - left) >> 1);
			// debug
			cout << "left: " << left << ", right: " << right << ", mid: " << mid << endl;
			if(isBadVersion(mid)){
				right = mid - 1;
			}
			else{
				left = mid + 1;
			}
		}
		return left;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		cout << "ans: " << sol.firstBadVersion(n) << endl;
	}
	return 0;
}
