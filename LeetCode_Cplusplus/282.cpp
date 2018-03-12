#include <bits/stdc++.h>
using namespace std;

// DFS
class Solution {
private: 
	vector<string> ans;
	stringstream stream;
	
	void DFS(string num, int target, string path, int s, int e, int res, int preVal){
		if(s > e){
			if(res == target){
				ans.push_back(path);
			}
			return;
		}
		string str;
		int tmpVal;		
		if(s == 0){
			if(num[s] == '0'){
				DFS(num, target, path + "0", s + 1, e, 0, 0);
			}
			else{
				for(int i = 1; i <= e + 1; i++){
					str = num.substr(0, i);
					stream << str;
					stream >> tmpVal;
					stream.clear();
					DFS(num, target, path + str, i, e, tmpVal, tmpVal);
				}
			}
		}
		else{
			if(num[s] == '0'){
				DFS(num, target, path + "+0", s + 1, e, res, 0);
				DFS(num, target, path + "-0", s + 1, e, res, 0);
				DFS(num, target, path + "*0", s + 1, e, res - preVal, 0);
			}
			else{
				for(int i = 1; i <= e - s + 1; i++){
					str = num.substr(s, i);
					stream << str;
					stream >> tmpVal;
					stream.clear();
					DFS(num, target, path + "+" + str, s + i, e, res + tmpVal, tmpVal);
					DFS(num, target, path + "-" + str, s + i, e, res + (-tmpVal), -tmpVal);
					DFS(num, target, path + "*" + str, s + i, e, res - preVal + tmpVal * preVal, tmpVal * preVal);
				}
			}
		}
	}

public:
    vector<string> addOperators(string num, int target) {
		ans.clear();
        int n = num.length();
		if(n == 0){
			return ans;
		}
		DFS(num, target, "", 0, n - 1, 0, 0);
		return ans;
    }
};

int main(int argc, char** argv){
	Solution sol;
	string num;
	int target;
	while(cin >> num >> target){
		vector<string> ans = sol.addOperators(num, target);
		// console output
		if(ans.empty()){
			cout << "empty!" << endl;
		}
		else{
			for(string val: ans){
				cout << val << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
