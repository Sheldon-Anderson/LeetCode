#include <bits/stdc++.h>
using namespace std;

#define LL long long

// binary_search
class Solution {
public:
    bool isPerfectSquare(int num) {
       if(num < 0){
		   return false;
	   }
	   int left = 0, right = num;
	   while(left <= right){
		   int mid = left + ((right - left) >> 1);
		   if((LL)mid * (LL)mid == (LL)num){
			   return true;
		   }
		   else if((LL)mid * (LL)mid < (LL)num){
			   left = mid + 1;
		   }
		   else if((LL)mid * (LL)mid > (LL)num){
			   right = mid - 1;
		   }
	   }
	   return false;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans: " << sol.isPerfectSquare(num) << endl;
	}
	return 0;
}
