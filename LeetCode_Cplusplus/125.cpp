#include<bits/stdc++.h>
using namespace std;

// two pointers
class Solution {
public:
    bool isPalindrome(string s) {
		int n = s.length();
        if(n <= 1){
			return true;
		}
		int left = 0, right = n - 1;
		while(left < right){
			// while(left < right && !isalpha(s[left]) && !isdigit(s[left])){ also correct!
			while(left < right && !isalnum(s[left])){
				left++;
			}
			//while(left < right && !isalpha(s[right]) && !isdigit(s[right])){ also correct!
			while(left < right && !isalnum(s[right])){
				right--;
			}
			if(left < right && (tolower(s[left]) != tolower(s[right]))){
				return false;
			}
			left++;
			right--;
		}
		return true;
    }
};

int main(){
	Solution sol;
	string s;
	while(getline(cin, s)){
		cout << "ans: " << sol.isPalindrome(s) << endl;
	}
	return 0;
}
