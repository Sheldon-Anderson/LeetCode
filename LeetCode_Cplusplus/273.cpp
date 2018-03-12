#include <bits/stdc++.h>
using namespace std;

class Solution {
private: 
	string tens[20] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
	string decades[10] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

	string getStr(int digit){
		string res = "";
		int d = digit / 100;
		if(d > 0){
			digit %= 100;
			res += (tens[d] + " Hundred ");
		}
		if(digit > 0 && digit < 20){
			res += (tens[digit] + " ");
		}
		else if(digit >= 20){
			res += (decades[digit / 10] + " ");
			if(digit % 10){
				res += (tens[digit % 10] + " ");
			}
		}
		return res;
	}

public:
    string numberToWords(int num) {
        if(num == 0){
			return "Zero";
		}
		string ans = "";
		int d = num / 1000000000;
		if(d > 0){
			num %= 1000000000;
			ans += (getStr(d) + "Billion ");
		}
		d = num / 1000000;
		if(d > 0){
			num %= 1000000;
			ans += (getStr(d) + "Million ");
		}
		d = num / 1000;
		if(d > 0){
			num %= 1000;
			ans += (getStr(d) + "Thousand ");
		}
		if(num){
			ans += getStr(num);
		}
		ans = ans.substr(0, ans.length() - 1);
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int num;
	while(cin >> num){
		cout << "ans: " << sol.numberToWords(num) << endl;
	}
	return 0;
}
