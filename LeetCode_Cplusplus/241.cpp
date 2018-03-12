#include <bits/stdc++.h>
using namespace std;

// divide and conquer
class Solution {
private:
	vector<int> DFS(vector<int> vec, int s, int e){
		if(s == e){
			return vector<int>{vec[s]};
		}
		vector<int> ans;
		for(int i = s; i <= e; i++){
			if(vec[i] < 0){
				vector<int> left = DFS(vec, s, i - 1);
				vector<int> right = DFS(vec, i + 1, e);
				for(int v1: left){
					for(int v2: right){
						int val;
						if(vec[i] == -1){
							val = v1 + v2;
						}
						else if(vec[i] == -2){
							val = v1 - v2;
						}
						else if(vec[i] == -3){
							val = v1 * v2;
						}
						ans.push_back(val);
					}
				}
			}
		}
		return ans;
	}

public:
    vector<int> diffWaysToCompute(string input) {
		int n = input.length();
		if(n == 0){
			return vector<int>();
		}
		int num = 0;
		vector<int> vec;
        for(int i = 0; i <= n - 1; i++){
			if(input[i] >= '0' && input[i] <= '9'){
				num = 10 * num + (input[i] - '0');
			}
			else{
				vec.push_back(num);
				num = 0;
				if(input[i] == '+'){
					vec.push_back(-1);
				}
				else if(input[i] == '-'){
					vec.push_back(-2);
				}
				else if(input[i] == '*'){
					vec.push_back(-3);
				}
			}
		}
		vec.push_back(num);
		return DFS(vec, 0, vec.size() - 1);
    }
};

int main(int argc, char** argv){
	Solution sol;
	string input;
	while(cin >> input){
		vector<int> ans = sol.diffWaysToCompute(input);
		// output
		for(int val: ans){
			cout << val << " ";
		}
		cout << endl;
	}
	return 0;
}
