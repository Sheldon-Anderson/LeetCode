#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
        // Exceptional Case: 
		if(num1 == "" || num1 == "0"){
			return num2;
		}
		if(num2 == "" || num2 == "0"){
			return num1;
		}
		int n1 = num1.length(), n2 = num2.length();
		int digit, carry = 0;
		int i = 0, j = 0;
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string ans;
		while(i <= n1 - 1 && j <= n2 - 1){
			digit = (num1[i] - '0') + (num2[j] - '0') + carry;
			carry = digit / 10;
			ans.insert(ans.begin(), digit % 10 + '0');
			i++;
			j++;
		}
		while(i <= n1 - 1){
			digit = (num1[i] - '0') + carry;
			carry = digit / 10;
			ans.insert(ans.begin(), digit % 10 + '0');
			i++;
		}
		while(j <= n2 - 1){
			digit = (num2[j] - '0') + carry;
			carry = digit / 10;
			ans.insert(ans.begin(), digit % 10 + '0');
			j++;
		}
		if(carry){
			ans.insert(ans.begin(), '1');
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string num1, num2;
	while(cin >> num1 >> num2){
		cout << "ans: " << sol.addStrings(num1, num2) << endl;
	}
	return 0;
}
