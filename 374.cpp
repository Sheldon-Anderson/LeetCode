#include <bits/stdc++.h>

using namespace std;

// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n, mid = -1;
		while(left <= right){
			mid = left + ((right - left) >> 1);
			if(guess(mid) == 0){
				break;
			}
			else if(guess(mid) == -1){
			    right = mid - 1;
			}
			else if(guess(mid) == 1){
				left = mid + 1;
			}
		}
		return mid;
    }
};

int main(int argc, char** argv){
	
	return 0;
}
