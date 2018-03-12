#include<bits/stdc++.h>

using namespace std;

// stack + greedy
class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
		// Exceptional Case: 
		if(!k){
			return num;
		}
		if(k >= n){
			return "0";
		}
		int cnt = 0;
		stack<char> st;
		// remove k elements
		for(int i = 0; i <= n - 1; i++){
			while(!st.empty() && cnt < k){
				if(st.top() > num[i]){
					st.pop();
					cnt++;
				}
				else{
					break;
				}
			}
			st.push(num[i]);
		}
		for(int i = 1; i <= k - cnt; i++){
			st.pop();
		}
		// get answer
		string ans = "";
		while(!st.empty()){
			ans += st.top();
			st.pop();
		}
		// remove leading zeros
		int N = ans.length();
		int pos = -1;
		for(int i = N - 1; i >= 0; i--){
			if(ans[i] != '0'){
				pos = i;
				break;
			}
		}
		if(pos == -1){
			return "0";
		}
		ans = ans.substr(0, pos + 1);
		// reverse
		reverse(ans.begin(), ans.end());
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string num;
	int k;
	while(cin >> num >> k){
		cout << "ans: " << sol.removeKdigits(num, k) << endl;
	}
	return 0;
}
