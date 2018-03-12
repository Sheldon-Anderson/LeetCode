#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
	bool checkVowels(char c){
		return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'
			|| c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
	}

public:
    string reverseVowels(string s) {
        int n = s.length();
		if(n <= 1){
			return s;
		}
		int left = 0, right = n - 1;
		while(left < right){
			while(!checkVowels(s[left]) && left < right){
				left++;
			}
			while(!checkVowels(s[right]) && left < right){
				right--;
			}
			if(left < right){
				swap(s[left], s[right]);
				left++;
				right--;
			}
		}
		return s;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string s;
	while(getline(cin, s)){
		cout << "ans: " << sol.reverseVowels(s) << endl;
	}
	return 0;
}
