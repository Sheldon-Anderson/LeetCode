#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        int n = s.length();
		// Exceptional Case: 
		if(n == 0 || numRows == 1 || n <= numRows){
			return s;
		}
		string ans, tmp = "#";
		int step = 2 * numRows - 2;
		for(int i = 0; i <= numRows - 1; i++){
			int j = i;
			if(i == 0 || i == (numRows - 1)){
				while(j <= n - 1){
					tmp[0] = s[j];
					ans += tmp;
					j += step;
				}
			}
			else{
				int ss = step - i * 2;
				while(j <= n - 1){
					tmp[0] = s[j];
					ans += tmp;
					j += ss;
					ss = step - ss;
				}
			}
		}
		return ans;
    }
};

int main(){
	Solution sol;
	string s;
	int numRows;
	while(cin >> s >> numRows){
		cout << "ans: " << sol.convert(s, numRows) << endl;
	}
	return 0;
}
