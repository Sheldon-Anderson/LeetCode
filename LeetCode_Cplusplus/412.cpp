#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<string> fizzBuzz(int n) {
		vector<string> ans;
        if(n <= 0){
			return ans;
		}
		// transfer from integer to string
		stringstream stream;
		string str;
		for(int i = 1; i <= n; i++){
			if(!(i % 15)){
				ans.push_back("FizzBuzz");
			}
			else if(!(i % 3)){
				ans.push_back("Fizz");
			}
			else if(!(i % 5)){
				ans.push_back("Buzz");
			}
			else{
				stream << i;
				stream >> str;
				stream.clear();
				ans.push_back(str);
			}
		}
		// get answer
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	int n;
	while(cin >> n){
		vector<string> ans = sol.fizzBuzz(n);
		// console output
		for(string s: ans){
			cout << s << " ";
		}
		cout << endl;
	}
	return 0;
}
