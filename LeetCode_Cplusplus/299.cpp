#include <bits/stdc++.h>
using namespace std;

// map
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.length();
		if(n == 0){
			return "0A0B";
		}
		map<char, int> m1, m2;
		int cnt_A = 0, cnt_B = 0;
		// count A
		for(int i = 0; i <= n - 1; i++){
			if(secret[i] == guess[i]){
				cnt_A++;
				secret[i] = guess[i] = '#';
			}
		}
		// count B
		for(int i = 0; i <= n - 1; i++){
			if(secret[i] != '#'){
				m1[secret[i]]++;
			}
			if(guess[i] != '#'){
				m2[guess[i]]++;
			}
		}
		for(auto &p: m1){
			if(m2.count(p.first)){
				cnt_B += min(m1[p.first], m2[p.first]);
			}
		}
		// get answer
		stringstream stream;
		string str_A, str_B;
		stream << cnt_A;
		stream >> str_A;
		stream.clear();
		stream << cnt_B;
		stream >> str_B;
		stream.clear();
		return str_A + "A" + str_B + "B";
    }
};

int main(int argc, char** argv){
	Solution sol;
	string secret, guess;
	while(cin >> secret >> guess){
		cout << "secret: " << secret << ", guess: " << guess << endl;
		cout << "ans: " << sol.getHint(secret, guess) << endl;
	}
	return 0;
}
