#include<bits/stdc++.h>
using namespace std;

#define LL long long

class Solution {
public:
    int myAtoi(string str) {
		int n = str.length();
		// Exceptional Case: 
		if(n == 0){
			return 0;
		}
		// LL num = 0; LLONG_MAX = 9223372036854775807, still too small
		double num = 0;
		int sign = 0;
		for(int i = 0; i <= n - 1; i++){
			if(str[i] == ' '){
				if(!sign){
					continue;
				}
				else{
					break;
				}
			}
			else if(str[i] >= '0' && str[i] <= '9'){
				if(!sign){
					sign = 1;
				}
				num = num * 10 + (str[i] - '0');
			}
			else if(str[i] == '+' || str[i] == '-'){
				if(!sign){
					sign = (str[i] == '+')? 1: -1;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		if(sign == -1){
			num = -num;
		}
		int ans = 0;
		// debug
		// cout << "num: " << num << endl;
		// cout << "LL max: " << LLONG_MAX << endl;
		if(num >= (double)INT_MIN && num <= (double)INT_MAX){
			ans = num;
		}
		else if(num > (double)INT_MAX){
			ans = INT_MAX;
		}
		else if(num < (double)INT_MIN){
			ans = INT_MIN;
		}
        return ans;
    }
};

int main(){
	Solution sol;
	string str;
	while(cin >> str){
		cout << "ans: " << sol.myAtoi(str) << endl;
	}
	return 0;
}
