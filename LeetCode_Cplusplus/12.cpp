#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        int list_int[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
		string list_roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
		string ans = "";
		while(num > 0){
			for(int i = 0; i <= 12; i++){
				if(num >= list_int[i]){
					ans += list_roman[i];
					num -= list_int[i];
					break;
				}
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans: " << sol.intToRoman(num) << endl;
	}
	return 0;
}
