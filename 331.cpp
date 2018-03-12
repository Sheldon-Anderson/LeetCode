#include <bits/stdc++.h>
using namespace std;

/*
// N(null) = N(node) + 1
// Accepted
class Solution {
public:
    bool isValidSerialization(string preorder) {
        int n = preorder.size();
		if(!n){
			return false;
		}
		// transfer
		istringstream iss(preorder);
		string str;
		vector<string> vec;
		while(getline(iss, str, ',')){
			vec.push_back(str);
		}
		// judge 1
		int N = vec.size();
		if(N == 1){
			return vec[0] == "#";
		}
		// count
		int cnt_null = 0, cnt_node = 0;				
		for(int i = 0; i <= N - 1; i++){
			if(vec[i] == "#"){
				cnt_null++;
			}
			else{
				cnt_node++;
			}
		}
		// judge 2
		if(cnt_null != (cnt_node + 1)){
			return false;
		}
		// check subtree
		cnt_null = cnt_node = 0;
		int start = 0, end;
		while(start <= N - 1){
			if(vec[start] == "#"){
				return start == (N - 1);
			}
			end = start + 1;
			while(end <= N - 1){
				if(vec[end] == "#"){
					cnt_null++;
				}
				else{
					cnt_node++;
				}
				if(cnt_null == (cnt_node + 1)){
					break;
				}
				end++;
			}
			// judge 3
			if(end == N){
				return false;
			}
			start = end + 1;
			cnt_node = cnt_null = 0;
		}
		return true;
    }
};
*/

/*
// N(indegree) = N(outdegree)
// Accepted
class Solution {
public:
    bool isValidSerialization(string preorder) {
		int n = preorder.size();
		if(!n){
			return false;
		}
		// transfer
		istringstream iss(preorder);
		vector<string> vec;
		string str;
		while(getline(iss, str, ',')){
			vec.push_back(str);
		}
		// count: indegree -> '+', outdegree -> '-'
		int degree = -1;
		int N = vec.size();
		for(int i = 0; i <= N - 1; i++){
			degree++;
			if(degree > 0){
				return false;
			}
			if(vec[i] != "#"){
				degree -= 2;
			}
		}
		return !degree;
	}
};
*/

// stack
class Solution {
public:
    bool isValidSerialization(string preorder) {
		int n = preorder.length();
		if(!n){
			return false;
		}
		// transfer
		istringstream iss(preorder);
		string str;
		vector<string> vec;
		while(getline(iss, str, ',')){
			vec.push_back(str);
		}
		// stack manipulation
		stack<string> st;
		int N = vec.size();
		for(int i = 0; i <= N - 1; i++){
			if(st.empty()){
				st.push(vec[i]);
			}
			else{
				if(vec[i] != "#"){
					st.push(vec[i]);
				}
				else{
					string s1 = st.top();
					// st.pop(); will cause an error!
					if(s1 != "#"){
						st.push(vec[i]);
					}
					else{
						st.pop();
						if(st.empty()){
							return false;
						}
						string s2 = st.top();
						if(s2 != "#"){
							st.pop();
							i--;
						}
						else{
							return false;
						}
					}
				}
			}
		}
		// get answer
		if(!st.empty()){
			string top = st.top();
			st.pop();
			return top == "#" && st.empty();
		}
		return false;
	}
};

int main(int argc, char** argv){
	Solution sol;
	string preorder;
	while(cin >> preorder){
		cout << "ans: " << sol.isValidSerialization(preorder) << endl;
	}
	return 0;
}
